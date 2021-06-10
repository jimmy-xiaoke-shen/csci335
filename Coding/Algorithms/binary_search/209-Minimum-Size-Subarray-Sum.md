# LC [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

We can use deque or two pointer to solve this problem in O(n). Here is a O(n log n) binary search solution

```cpp
class Solution {
public:
    bool good(int m, int target, vector<int>& prefix_sum){
        const int n = prefix_sum.size();
        int sum = 0;
        for (int i = 1; i < n && i + m - 1 < n; ++i){
            if (prefix_sum[i+m-1] - prefix_sum[i-1] >= target)return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        vector<int>prefix_sum( n + 1, 0);
        for (int i = 1; i <= n; ++i){
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }
        int l = 0, r = n, m = 0;
        while (l < r) {
            m = (l + r) / 2;
            if (good(m, target, prefix_sum)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return good(l, target, prefix_sum)? l : 0;
    }
};
```

O(n) solution can be found [here](https://jimmy-shen.medium.com/two-pointer-and-deque-f8f1aa45112)
