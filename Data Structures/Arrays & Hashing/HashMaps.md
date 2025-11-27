# HashMaps
HashMaps known as Dictionaries in Python is a DataStructure that stores **Values** by parring them up with **Keys**.

### Benefits
1. When working with large software systems we can use HashMaps to increase readability as we can use custom Keys in order to better organize information.

2. HashMaps allow how great time complexity as searching in a HashMap is **O(1)**, whereas arrays/linked lists are **O(n)**.

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
- Something that is super immportant to know is that once a Key is create that Key **CAN NOT BE CHANGED**.
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