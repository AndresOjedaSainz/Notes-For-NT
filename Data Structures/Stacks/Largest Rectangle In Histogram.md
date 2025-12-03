# Largest Rectangle In Histogram

## Difficulty - Hard

You are given an array of integers `heights` where `heights[i]` represents the height of a bar. The width of each bar is `1`.

Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a histogram.

### Example 1

`Input: heights = [7,1,7,2,2,4]`

`Output: 8`

### Example 2

`Input: heights = [1,3,7]`

`Output: 7`

### Constraints

- `1 <= heights.length <= 1000`
- `0 <= heights[i] <= 1000`

# Code Solution
```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # stores indices of bars in increasing height order
        max_area = 0

        for i in range(len(heights) + 1):
            current_height = heights[i] if i < len(heights) else 0

            while stack and current_height < heights[stack[-1]]:
                h = heights[stack.pop()]
                left = stack[-1] if stack else -1
                width = i - left - 1
                max_area = max(max_area, h * width)

            stack.append(i)

        return max_area
```

## Why this works
- Append a sentinel `0` height by iterating one past the array to flush all remaining bars from the stack.
- The stack contains indices of bars in strictly increasing height order; whenever a shorter bar appears, it defines the right boundary for taller bars so we can compute their maximal area.
- For each popped bar we know its left boundary (`stack[-1]`) and right boundary (`i`), so area = height × width.

## Complexity
- Time: `O(n)` because each index is pushed/popped at most once.
- Space: `O(n)` for the stack in the worst case (strictly increasing heights).

## Visualization (`heights = [2,1,5,6,2,3]`)

| Step | i | height | Stack (indices) | Action | `left` | `width` | Area |
|------|---|--------|-----------------|--------|--------|--------|------|
| 1 | 0 | 2 | [] | push 0 | — | — | — |
| 2 | 1 | 1 | [0] | `1 < heights[0]=2` → pop 0 | -1 | `1 - (-1) - 1 = 1` | `2 * 1 = 2` |
|   |   |   | [] | push 1 | — | — | — |
| 3 | 2 | 5 | [1] | push 2 | — | — | — |
| 4 | 3 | 6 | [1,2] | push 3 | — | — | — |
| 5 | 4 | 2 | [1,2,3] | `2 < heights[3]=6` → pop 3 | 2 | `4 - 2 - 1 = 1` | `6 * 1 = 6` |
|   |   |   | [1,2] | `2 < heights[2]=5` → pop 2 | 1 | `4 - 1 - 1 = 2` | `5 * 2 = 10` |
|   |   |   | [1] | `2 >= heights[1]=1` → stop, push 4 | — | — | — |
| 6 | 5 | 3 | [1,4] | push 5 | — | — | — |
| 7 | 6 | 0 (sentinel) | [1,4,5] | `0 < heights[5]=3` → pop 5 | 4 | `6 - 4 - 1 = 1` | `3 * 1 = 3` |
|   |   |   | [1,4] | `0 < heights[4]=2` → pop 4 | 1 | `6 - 1 - 1 = 4` | `2 * 4 = 8` |
|   |   |   | [1] | `0 < heights[1]=1` → pop 1 | -1 | `6 - (-1) - 1 = 6` | `1 * 6 = 6` |
|   |   |   | [] | push sentinel index 6 |

- When we pop 2 (height 5), the nearest smaller bar on the left is at index 1, and the right boundary is current index 4, so width is `4 - 1 - 1 = 2`, covering bars at indices 2 and 3. Area = `5 * 2 = 10`.
- The sentinel iteration (`i = len(heights)`) uses a height of `0` to flush the remaining stack, ensuring every bar is evaluated.

Another example (`heights = [4,4,2,3]`):

| Pop | `h` | Stack after pop | `left` | `i` | `width = i - left - 1` | Bars covered | Area |
|-----|-----|-----------------|--------|-----|------------------------|--------------|------|
| pop index 1 (height 4) | 4 | [0] | 0 | 2 | `2 - 0 - 1 = 1` | index 1 only | 4 |
| pop index 0 (height 4) | 4 | [] | -1 | 2 | `2 - (-1) - 1 = 2` | indices 0–1 | 8 |

- When popping index 0, `left = -1` means no smaller bar to the left. Width becomes `2` (bars 0 and 1), demonstrating why the sentinel `-1` works.
