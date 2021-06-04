# [Max Character Distinct Words](https://binarysearch.com/problems/Max-Character-Distinct-Words)

```cpp
/*
jimmy shen
Time complexity: O(n*w*26) -> O(n*w)
Space complexity: O(n*w)
*/

bool common(vector<unordered_set<char>> & letters, int i, int j)
{
    for (auto c: letters[i])
    {
        // if c in letters[i] can be found in letters[j], common, return true
        if (letters[j].find(c) != letters[j].end()) return true; 
    }
    return false;
}

int solve(vector<string>& words) {
    const int n = words.size();
    vector<unordered_set<char>> letters(n);
    // put characters of each word into a unordered_set.
    for (int i = 0; i < n; ++i) 
    {
        for (auto c: words[i])
        {
            letters[i].insert(c);
        } 
    }
    int ret = 0;
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
        if (!common(letters, i, j))
        {
            int thisRet = words[i].size() + words[j].size();
            ret = max(ret, thisRet);
        }
    }
    return ret;
}
```

Runtime
```
Your code took 1916 milliseconds — faster than 4.20% in C++
```

As you may know, although the hash table has the complexity of O(1), array also has the 
complexity of O(1). However, the array is much faster than hash table.
So if we replace the hash table to array, it will be faster.
Of course, since we only have 26 lower case letters, you can use 26 bits to solve the problem.
For the 26 bits one, the complexity is O(n\*w\*1) instead of O(n\*w\*26) although the final complexities 
are both O(n\*w). Try to code it up by yourself by using either one.

Python TLE solution for reference
```python
class Solution:
    def solve(self, words):
        n = len(words)
        char_sets = [set(word) for word in words]
        return max(len(words[i]) + len(words[j]) for i, j in  itertools.combinations(range(n), 2)
                                                if not (char_sets[i] & char_sets[j]))
```

