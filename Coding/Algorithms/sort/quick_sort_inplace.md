[Quicksort In-Place](https://www.hackerrank.com/challenges/quicksort3/problem)


```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(vector<int>& nums, int left, int right){
    // if the length of the subarray is less or equal to 1
    // return
    // a[0], a[1]
    if (right - left + 1 <= 1) return;
    //int pivot_idx = right;
    int pivot = nums[right];
    int left_idx = left;
    for (int i = left; i < right; ++i){
        /*
        Check the current element x
        If x <= pivot {
        swap(orange, gray)
        Orange ++
        }
        Else: continue
        */
        int x = nums[i];
        if (x <= pivot) {
            swap(nums[i], nums[left_idx]);
            left_idx++;
        } 
    }
    swap(nums[right], nums[left_idx]);
    for (auto x: nums)cout << x << " ";
    cout << endl;
    quick_sort(nums, left, left_idx - 1);
    quick_sort(nums, left_idx + 1, right);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    quick_sort(nums, 0, n - 1);
    return 0;
}

```
