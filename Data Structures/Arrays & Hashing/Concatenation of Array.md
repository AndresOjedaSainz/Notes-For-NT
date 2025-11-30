# 1929 - Concatenation of Array
### Difficulty - Easy

You are given an integer array `nums` of length `n`. Create an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n` (0-indexed).

Specifically, `ans` is the concatenation of two `nums` arrays.

Return the array `ans`.

Example 1:

`Input: nums = [1,4,1,2]`

`Output: [1,4,1,2,1,4,1,2]`

Example 2:

`Input: nums = [22,21,20,1]`

`Output: [22,21,20,1,22,21,20,1]`

# Code Solution:
```python
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = nums + nums
        return ans
```
- Time: O(n) because list concatenation copies all n elements twice.
- Space: O(n) extra for the new list ans (2n elements, linear in input size).