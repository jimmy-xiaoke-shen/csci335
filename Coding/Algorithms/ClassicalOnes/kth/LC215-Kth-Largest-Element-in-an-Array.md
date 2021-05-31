# [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

This problem is interesting as from this problem you can learn sort, heap, multiset, 
divide and conque, quick select.

# Solution 1: sort
No need to explain
```cpp
/*
jimmy shen
time complexity: O(n log n)
space complexity: O(1)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k > n) return -1;
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
```

# Solution 2: heap  
Keep on putting elements into a heap, if we have more than K elements in the heap,
pop the smallest one as we need the Kth largest number and we have K + 1 elements now, 
the smallest one can not be the Kth largest number.  As we need pop the smallest number,
we need a min heap.

```cpp
/*
jimmy shen
time complexity: O(n log k)
space complexity: O(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k > n) return -1;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto num: nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
```
Runtime
```
Runtime: 24 ms, faster than 17.34% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.1 MB, less than 31.88% of C++ online submissions for Kth Largest Element in an Array.
```

Of course, if you want to use max heap (default in C++ the priority queue is max heap
however, in python the default one is min heap)

```cpp
/*
jimmy shen
time complexity: O(n log k)
space complexity: O(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        // change the problem from Kth largest to Kth smallest
        k = n - k + 1;
        if (k > n) return -1;
        priority_queue<int> maxHeap;
        for (auto num: nums)
        {
            maxHeap.push(num);
            if (maxHeap.size() > k) maxHeap.pop();
        }
        return maxHeap.top();
    }
};
```

# Solution 3: multiset  
We know that multiset in C++ is a balanced binary search tree (Red Balck Tree). Different
to min heap can only pop the minimum value and max heap can only pop the maximum value,
multiset can do both by: 
```cpp
#include <iostream>                                                                     
#include <set>                                                                          
                                                                                        
using namespace std;                                                                    
                                                                                        
int main()                                                                              
{                                                                                       
  multiset<int> myMultiset;                                                             
  myMultiset.insert(3);                                                                 
  myMultiset.insert(3);                                                                 
  myMultiset.insert(1);                                                                 
  cout << "myMultiset:" << endl;                                                        
  for (auto x: myMultiset)                                                              
  {                                                                                     
    cout << x << endl;                                                                  
  }                                                                                     
  auto minVal = *(myMultiset.begin());                                                  
  auto maxVal = *(--myMultiset.end());                                                  
  cout << "minVal" << minVal << endl; //output 1                                        
  cout << "maxVal" << maxVal << endl; //output 3                                        
  return 0;                                                                             
} 
```
Reference code
```cpp
/*
jimmy shen
time complexity: O(n log k)
space complexity: O(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        // change the problem from Kth largest to Kth smallest
        k = n - k + 1;
        if (k > n) return -1;
        multiset<int> kElements;
        for (auto num: nums)
        {
            kElements.insert(num);
            if (kElements.size() > k) kElements.erase(--kElements.end());
        }
        return *(--kElements.end());
    }
};
```

# Solution 4: quick select  
## non inplace  
```cpp
/*
jimmy shen
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    int quickSelect(vector<int> nums, int k)
    {
        const int n = nums.size();
        int pivot_idx = rand() % n;
        int pivot = nums[pivot_idx];
        vector<int> left, right;
        for (int i = 0; i < n; ++i)
        {
            if (i == pivot_idx) continue;
            if (nums[i] <= pivot)
            {
                left.push_back(nums[i]);
            } else 
            {
                right.push_back(nums[i]);
            }
        }
        if (left.size() == k - 1) return pivot;
        else if (left.size() >= k) return quickSelect(left, k);
        else return quickSelect(right, k - (left.size() + 1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        return quickSelect(nums, k);
    }
};
```
run time
```
Runtime: 8 ms, faster than 73.60% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 12 MB, less than 7.85% of C++ online submissions for Kth Largest Element in an Array.
```

## inplace 

```cpp
/*
jimmy shen
time complexity: O(n)
space complexity: O(1)
*/
class Solution {
public:
    /*
    Reference
    https://en.wikipedia.org/wiki/Quickselect
    function partition(list, left, right, pivotIndex) is
    pivotValue := list[pivotIndex]
    swap list[pivotIndex] and list[right]  // Move pivot to end
    storeIndex := left
    for i from left to right − 1 do
        if list[i] < pivotValue then
            swap list[storeIndex] and list[i]
            increment storeIndex
    swap list[right] and list[storeIndex]  // Move pivot to its final place
    return storeIndex
    */
    int partition(vector<int>& list, int left, int right,int pivot_index)
    {
        auto pivot_value = list[pivot_index];
        swap(list[pivot_index], list[right]);
        auto store_index = left;
        for(int i=left; i<=right;++i)
        {
            if (list[i] < pivot_value)
            {
                swap(list[i], list[store_index++]);
            } 
        }
        swap(list[store_index], list[right]);
        return store_index;
    }
    
    /*
    // Returns the k-th smallest element of list within left..right inclusive
    // (i.e. left <= k <= right).
    function select(list, left, right, k) is
    if left = right then   // If the list contains only one element,
        return list[left]  // return that element
    pivotIndex  := ...     // select a pivotIndex between left and right,
                           // e.g., left + floor(rand() % (right − left + 1))
    pivotIndex  := partition(list, left, right, pivotIndex)
    // The pivot is in its final sorted position
    if k = pivotIndex then
        return list[k]
    else if k < pivotIndex then
        return select(list, left, pivotIndex − 1, k)
    else
        return select(list, pivotIndex + 1, right, k)
    */
    int select(vector<int>& list, int left, int right,int k)
    {
        if (left == right)return list[left];
        auto pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(list, left, right, pivot_index);
        if (k == pivot_index)return list[pivot_index];
        else if(k < pivot_index)
        {
             return select(list, left, pivot_index - 1, k);
        }
        else
        {
            return select(list, pivot_index + 1, right, k);
        }
           
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        return select(nums, 0, nums.size()-1, nums.size()-k);
    }
};
```
run time
```
Runtime: 8 ms, faster than 73.60% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 9.8 MB, less than 97.14% of C++ online submissions for Kth Largest Element in an Array.
```
