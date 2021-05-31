# [LC 1 TwoSum](https://leetcode.com/problems/two-sum/)


# Solution 1: Two pointers
using two layer for loops to solve the problem in a brute force way. 
```cpp
/*
Jimmy Shen
Time complexity: O(n^2)
Space complxity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target) 
                {
                    return {i, j};
                }
            }
        return ret;
    }
};
```
Run time
```
Runtime: 620 ms, faster than 5.08% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 27.85% of C++ online submissions for Two Sum.
```

# Solution 2: binary search
Sort the nums first, as we need the index info, build a new vector which contains the 
index information. As the new vector is in sorted order, we can use bianry search to
replace the j loops in solution 1 by using binary search.

```cpp
/*
Jimmy Shen
Time complexity: O(n logn )
Space complxity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<pair<int, int>> numsIdx;
        for (int i = 0; i < n; ++i)
        {
            numsIdx.emplace_back(nums[i], i);
        }
        sort(numsIdx.begin(), numsIdx.end());
        vector<int> ret;
        for (int i = 0; i < n - 1; ++i)
        {
            pair<int, int> targetLowerBoud = make_pair(target - nums[i], -1);
            if (target - nums[i] == nums[i]) 
            {
                targetLowerBoud = make_pair(target - nums[i], i);
            }
            auto it = upper_bound(numsIdx.begin(), numsIdx.end(), targetLowerBoud);
            if (it != numsIdx.end() && it->first == target - nums[i]) 
            {
                ret.push_back(i);
                ret.push_back(it->second);
                return ret;
            }
            
        }
        return ret;
    }
};
```
Much faster than solution 1
```
Runtime: 16 ms, faster than 24.81% of C++ online submissions for Two Sum.
Memory Usage: 10.8 MB, less than 14.38% of C++ online submissions for Two Sum.
```
# Solution 3 
We can further improve our solution to O(n) by using a hash table.
This will change our thinking process a little bit. Previously, we stand on i and look 
for candidates forward. Now, we look backwards (lots of problems can be solved by 
using this trick. You need more practise).

As you are recording your history information, you can simply ask yourself, did I see 
my target in history? Then here comes the solution:
```cpp
/*
Jimmy Shen
Time complexity: O(n)
Space complxity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> ret;
        unordered_map<int, int> history;
        for (int i = 0; i < n; ++i)
        {
            int whatWeAreLookingFor = target - nums[i];
            if (history.find(whatWeAreLookingFor) != history.end())
            {
                return {history[whatWeAreLookingFor], i};
            }
            // add the current num into history for future checking
            history[nums[i]] = i;
        }
        return ret;
    }
};
```
As log(n) is a pretty small number, this solution has not a significant speed 
improvement.
```
Runtime: 20 ms, faster than 22.02% of C++ online submissions for Two Sum.
Memory Usage: 10.8 MB, less than 10.16% of C++ online submissions for Two Sum.
```
