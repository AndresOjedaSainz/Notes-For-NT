# Daily Temperatures

## Difficulty - Medium

You are given an array of integers `temperatures` where `temperatures[i]` represents the daily temperatures on the `ith` day.

Return an array `result` where `result[i]` is the number of days after the `ith` day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the `ith` day, set `result[i]` to `0` instead.

Example 1:

`Input: temperatures = [30,38,30,36,35,40,28]`

`Output: [1,4,1,2,1,0,0]`

Example 2:

`Input: temperatures = [22,21,20]`

`Output: [0,0,0]`

Constraints:

`1 <= temperatures.length <= 1000.`
`1 <= temperatures[i] <= 100.`

# Code Solution
```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        stack = []  # stores indices of days with decreasing temperatures

        for i in range(n - 1, -1, -1):
            # Pop every index whose temperature is not warmer than temperatures[i]
            while stack and temperatures[i] >= temperatures[stack[-1]]:
                stack.pop()

            if stack:
                result[i] = stack[-1] - i  # distance to the next warmer day

            stack.append(i)

        return result
```

## Why this works
- The stack holds indices in strictly decreasing temperature order, so the nearest warmer day is always at the top once cooler days are removed.
- Each index is pushed and popped at most once, so time complexity is `O(n)` and space complexity is `O(n)` for the result plus stack.

### Stack walk-through (`[73, 74, 75, 71, 69, 72, 76, 73]`)

| i | temp | stack (top→right) | Action/result[i] |
|---|------|-------------------|------------------|
| 7 | 73   | []                | Stack empty → result[7]=0; push 7 |
| 6 | 76   | [7]               | 76 ≥ temp[7]=73 → pop 7; stack empty → result[6]=0; push 6 |
| 5 | 72   | [6]               | 72 ≥ temp[6]=76? no → result[5]=6-5=1; push 5 → [6,5] |
| 4 | 69   | [6,5]             | 69 ≥ temp[5]=72? no → result[4]=5-4=1; push 4 → [6,5,4] |
| 3 | 71   | [6,5,4]           | 71 ≥ temp[4]=69 → pop 4; 71 ≥ temp[5]=72? no → result[3]=5-3=2; push 3 → [6,5,3] |
| 2 | 75   | [6,5,3]           | 75 ≥ temp[3]=71 → pop 3; 75 ≥ temp[5]=72 → pop 5; 75 ≥ temp[6]=76? no → result[2]=6-2=4; push 2 → [6,2] |
| 1 | 74   | [6,2]             | 74 ≥ temp[2]=75? no → result[1]=2-1=1; push 1 → [6,2,1] |
| 0 | 73   | [6,2,1]           | 73 ≥ temp[1]=74? no → result[0]=1-0=1; push 0 |

- The stack holds indices whose temperatures are strictly decreasing as you move left to right.
- While stack isn’t empty and today’s temperature is ≥ the temperature at the stack’s top index, pop the stack—those days aren’t strictly warmer anymore.
- After popping cooler/equal days, the stack top (if any) gives the index of the next warmer day, so result[i] = stack[-1] - i.
- Push the current index to keep it available for earlier days.

This shows exactly how the while stack and temperatures[i] >= temperatures[stack[-1]]: loop removes cooler/equal days and how we compute distances.