<h1 align="center">The 8 most common patterns to solve Leetcode Problems</h1>

## 1. Sliding Window

The Sliding Window technique is used when you need to process a serires of of data elements like a list or a string.

Sliding window is a linear scan technique for problems that ask for the best subsequence (contiguous subarray or substring) that satisfies a constraint such as maximum sum, minimum length, or a bounded number of unique items. Instead of recomputing the answer for every possible subarray, maintain a pair of indices `left` and `right` that describe the current window and update a running summary (sum, frequency map, number of distinct characters, etc.) as the window expands or shrinks.

### Core idea

1. **Expand the window** by moving `right` forward each iteration and incorporate the new element into the running summary.
2. **Check the constraint** on the current window; if it is violated, tighten the window by incrementing `left` and removing elements from the summary until the constraint holds again.
3. **Record answers** (length, sum, indices) while traversing, usually when the constraint is satisfied.

### Implementation notes

- Use fixed-size sliding window when the window length is constant; you only advance `left` when `right - left + 1` exceeds the target length.
- For dynamic windows (e.g., at most `k` distinct characters), maintain auxiliary structures such as a hash map for counts.
- Each element is added and removed at most once, so the time complexity is `O(n)` and space is `O(1)` for fixed windows or `O(k)` for dynamic windows where `k` is constraint-dependent.
- Beware of off-by-one updates: update the answer after verifying the constraint, and ensure the running summary stays consistent with the window bounds.

# 2. Subset Pattern

We use the Subset pattern/technique when we want to find all possible combinations of a given set. Repetitions may or may not be allowed depending on the questions being asked.

- Used when each element has a binary decision (include/exclude) and you must enumerate combinations, subsets, or explore a decision tree such as in `subsets`, `combination sum`, or `palindrome partitioning`.
- Implement as DFS/backtracking: maintain a `path` list, iterate from a `start` index, append a choice, recurse, then backtrack by removing the last choice so the next branch starts clean.
- Base case typically triggers once the start index reaches the array length or a target length/total is satisfied; capture a copy of the current `path` in the results at that point.
- Complexity grows exponentially (`O(2^n)` for basic subsets) because every element can be either chosen or skipped; recursion depth is `O(n)` and additional memory is for the accumulated results.
- Sort the input and skip duplicates that appear at the same recursion depth (`if i > start and nums[i] == nums[i-1]: continue`) to prevent repeated subsets.
- Prune branches early using remaining length or sum checks (e.g., stop exploring when `remaining < 0` or when `path` already exceeds the target size).

# 3. Modified Binary Search
# 4. Top K Elements
# 5. Binary Tree DFS
# 6. Topological Sort
# 7. Binary Tree BFS
# 8. Two Pointer Technique