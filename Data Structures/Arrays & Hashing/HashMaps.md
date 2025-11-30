# HashMaps
HashMaps known as Dictionaries in Python is a DataStructure that stores **Values** by parring them up with **Keys**.

### Benefits
1. When working with large software systems we can use HashMaps to increase readability as we can use custom Keys in order to better organize information.

2. HashMaps allow for great time complexity as searching in a HashMap is **O(1)**, whereas arrays/linked lists are **O(n)**.

### How do we create them?
- We would take a pre existing dataset normally from an array/list and set up the pairs of keys and values.
- Now we would do this by creating something called a **Hash Function**. Now these can be pretty complex especially the larger your dataset is.
- The biggest problem is when we encounter collisions. This occurs when we try mapping a new value to a already pre existing key.
    - Example: 
        ```python
            France = index0
            USA = index0
            # Error: Index Already Used
            ```
- Something that is super important to know is that once a Key is create that Key **CAN NOT BE CHANGED**.
    - Keys must be immutable data type, that is why you can't set an array to be a key.
    - How ever we can use a **tuple** as a key.

# Coding HashMaps
Lets now code up some HashMaps in python!
```python
# We can initialize the HashMap in a couple ways.
city_map = {}
#or
city_map2 = dict()

# Now lets add some data
cities = ['NewYork', "Miami", "Orlando"]
# Here is what not to do
"""
city_map["America"].append(cities)
This is because you are technically adding multiples values to one key.
Instead initialize that key's value to an array
Then add the values
"""
city_map["America"] = []
city_map["America"] += cities
print(city_map["America"])

# Console output
['NewYork', 'Miami', 'Orlando']
```
Now usually when working with HashMaps we know that type of data we want to store so instead of constantly initializing each value type stored in each key, we do it before hand to the whole hashmap.
We use **defualtdict(list)**, this says that each now key will have a list as it's vaule. you could also do **defualtdict(int)**, **defualtdict(str)**, and **defualtdict(set)**.

#### Important
This does not force the values and keys to be strings, ints, list, etc. All this does is set empty values to be empty strings **""** for example in defualtdict(str).
#### Example: 
```python
from collections import defaultdict

m = defaultdict(str)

m["a"] = 1
m["b"] = "hello"
m["c"] = [1, 2, 3]
m["d"] = True
m[30] = "Huh"
```
### Retrieving Data
When Using HashMaps we have different ways of retrieving our data.
#### Example:
**hashmap.keys()** - This allows us to get all the keys in said HashMap. It returns it in the form of a list.
**hashmap.values()** - Very similar to hashmap.keys() but instead of keys it returns the values.
**hashmap.items()** - This ia combination of the two previous functions as it returns the pairs of Kays and Values in the form of a list as tuples.

# Example LeetCode Problem!
Now lets do a LeetCode Medium Problem using what we just learned

## 49. Group Anagrams
### Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Example 1:

`Input: strs = ["eat","tea","tan","ate","nat","bat"]`

`Output: [["bat"],["nat","tan"],["ate","eat","tea"]]`

Explanation:

- There is no string in strs that can be rearranged to form "bat".
- The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
- The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

`Input: strs = [""]`

`Output: [[""]]`

Example 3:

`Input: strs = ["a"]`

`Output: [["a"]]`

## Code:
```python
from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagram = defaultdict(list)
        result = []
        for s in strs:
            key = tuple(sorted(s))
            anagram[key].append(s)
        for value in anagram.values():
            result.append(value)
        
        return result
```
- **defaultdict(list):** Each anagram group needs to hold multiple strings, so the value for each key should be a list. Using defaultdict(list) auto-creates an empty list the first time a key is seen, so you can call anagram[key].append(s) without checking/initializing manually.

- **key = tuple(sorted(s)):** We need a hashable, consistent representation of the letters in a word so all anagrams share the same key. Sorting the characters gives a canonical order; wrapping in a tuple makes it immutable and hashable, so it can be used as a dict key (a list from sorted is not hashable).