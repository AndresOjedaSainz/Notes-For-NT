# Evaluate Reverse Polish Notation
## Difficulty - Medium

You are given an array of strings tokens that represents a **valid** arithmetic expression in `Reverse Polish Notation.`

Return the integer that represents the evaluation of the expression.

- The operands may be integers or the results of other operations.
- The operators include `'+'`, `'-'`, `'*'`, and `'/'`.
- Assume that division between integers always truncates toward zero.

Example 1:

`Input: tokens = ["1","2","+","3","*","4","-"]`

`Output: 5`

`Explanation: ((1 + 2) * 3) - 4 = 5`

Constraints:

- 1 <= tokens.length <= 1000.
- tokens[i] is `"+"`, `"-"`, `"*"`, or `"/"`, or a string representing an integer in the range `[-100, 100]`.

# Code Solution
```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        if not tokens:
            return 0
        
        plus = '+'
        minus = '-'
        multiply = '*'
        divide = '/'


        for token in tokens:
            # Handle positive integers directly
            if token.isdigit():
                stack.append(int(token))
            # Handle negative integers manually (starts with '-' plus digits)
            elif token[0] == '-' and token[1:].isdigit() and len(token) > 1:
                stack.append(int(token))
            else:
                if len(stack) >= 2 and token == plus:
                    num2 = stack.pop()
                    num1 = stack.pop()
                    sum = num1 + num2
                    stack.append(sum)
                elif len(stack) >= 2 and token == minus:
                    num2 = stack.pop()
                    num1 = stack.pop()
                    sum = num1 - num2
                    stack.append(sum)
                elif len(stack) >= 2 and token == multiply:
                    num2 = stack.pop()
                    num1 = stack.pop()
                    sum = num1 * num2
                    stack.append(sum)
                elif len(stack) >= 2 and token == divide:
                    num2 = stack.pop()
                    num1 = stack.pop()
                    # Truncate toward zero 
                    sum = int(num1 / num2)
                    stack.append(sum)
        return stack[-1]
```

## Things to Consider

### What is Reversed Polish Notation?
Reverse Polish notation (RPN), or postfix notation, writes arithmetic expressions so every operator comes after its operands, eliminating the need for parentheses.
 Example: the usual infix `3 + 4 * 2` becomes `3 4 2 * +`. To evaluate, scan left to right with a stack: push numbers, and when you see an operator pop the right number of operands (two for binary ops), apply it, and push the result. 
 Because the order of pushes/pops encodes precedence, you never need parentheses, `3 4 + 2 *` yields `(3 + 4) * 2`, while `3 4 2 * +` yields `3 + (4 * 2)`.

### Less Lines of Code
I know my solution has more lines than needed I just wanted to show the popping processes and handling it.
Another way you could have handled the code is like this.
```python
else:
    num2 = stack.pop()
    num1 = stack.pop()

    if token == '+':
        stack.append(num1 + num2)
    elif token == '-':
        stack.append(num1 - num2)
    elif token == '*':
        stack.append(num1 * num2)
    elif token == '/':
        stack.append(int(num1 / num2))
```

### Logic
Lets look at some specific lines and analyze their purpose.
```python
elif token[0] == '-' and token[1:].isdigit() and len(token) > 1:
```
This line is really important and crucial to handling negatives properly.
Remember we are working with strings and each `token` in `tokens` can have multiple characters in its string.
For Example: `-11` is technically `token[0] = '-'`, `token[1] = '1'`, and `token[2] = 1`.
So we need to check if hey this string length is greater 1, is an integer, and the first index is a negative symbol? Then we are working with a valid negative number.
We have to do this since the operation `.isdigit()` will return `False` since it only handles strings that don't have negative symbols. This is why we slice it with `token[1:].isdigit()`.
Since that checks if every character after the first index is a valid integer.
Lastly, the reason we have a length check is because if we try using `token[1:].isdigit()` and we just have a   `'-'` symbol it might throw some errors so this is just keep the code process safe.

```python
sum = int(num1 / num2)
```
- `num1 / num2 `performs floating-point division so we get the exact quotient, including any fractional part.
- Wrapping with `int(...)` truncates the result toward zero drops everything after the decimal while keeping the sign. So 2.7 becomes 2, -2.7 becomes -2.

We do it that way because LeetCode’s RPN spec says division should truncate toward zero (not floor). “Truncate toward zero” means move the value closer to zero by removing the fractional part: positive values round down, negative values round up, always stopping at the integer whose absolute value is smaller.