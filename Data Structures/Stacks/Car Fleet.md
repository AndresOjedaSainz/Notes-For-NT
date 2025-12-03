# Car Fleet

## Difficulty - Medium

There are `n` cars traveling to the same destination on a one-lane highway.

You are given two arrays of integers `position` and `speed`, both of length `n`.

- `position[i]` is the position of the `ith` car (in miles).
- `speed[i]` is the speed of the `ith` car (in miles per hour).
- The destination is at position `target` miles.

A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.

A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.

If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.

Return the number of different car fleets that will arrive at the destination.

### Example 1

`Input: target = 10, position = [1,4], speed = [3,2]`

`Output: 1`

Explanation: The cars starting at 1 (speed 3) and 4 (speed 2) become a fleet, meeting each other at 10, the destination.

### Example 2

`Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]`

`Output: 3`

Explanation: The cars starting at 4 and 7 become a fleet at position 10. The cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there are 3 car fleets that will arrive at the destination.

### Constraints

- `n == position.length == speed.length`
- `1 <= n <= 1000`
- `0 < target <= 1000`
- `0 < speed[i] <= 100`
- `0 <= position[i] < target`
- All the values of `position` are unique.

# Code Solution
```python
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [[p, s] for p, s in zip(position, speed)]
        stack = []

        for p, s in sorted(pair)[::-1]:
            stack.append((target - p) / s)
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()

        return len(stack)
```

## Why this works
- Sort cars by position descending (closest to target first). When scanning from right to left, every car only needs to “see” the fleet ahead.
- `stack` stores arrival times to the target. If a following car’s time is less than or equal to the one ahead, it catches up before reaching the target, so the two merge into the same fleet (pop the later time).
- Counting the remaining times equals counting car fleets.

## Complexity
- Time: `O(n log n)` for sorting the cars, `O(n)` for the scan.
- Space: `O(n)` to store the position-speed pairs and the arrival-time stack.

## Visualization (`target = 12`, positions = [10, 8, 3, 2], speeds = [2, 4, 2, 1])

| Car | Position | Speed | Time to target | Stack of times | Fleet Count |
|-----|----------|-------|----------------|----------------|-------------|
| A   | 10       | 2     | `(12-10)/2 = 1` | [1]           | 1 |
| B   | 8        | 4     | `(12-8)/4 = 1`  | [1] (B catches A, same time) | 1 |
| C   | 3        | 2     | `(12-3)/2 = 4.5` | [1, 4.5]      | 2 |
| D   | 2        | 1     | `(12-2)/1 = 10`  | [1, 4.5, 10]  | 3 |

- Cars are processed from closest to farthest. Car B’s arrival time (1 hour) is ≤ the top of the stack (1), so it merges with car A’s fleet.
- Car C can’t catch up before reaching the target, so it forms its own fleet with time 4.5, and the stack grows.
- Car D’s time 10 > 4.5, so it creates yet another fleet.
