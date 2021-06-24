#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> a){
   for (auto x: a)cout << x << " ";
   cout << endl;
}

void insertation_sort(vector<int> &nums)
{
   // sort(nums.begin(), nums.end());
   const int n = nums.size();
   if (n <= 1) return;
   for (int i = 1; i < n; ++i) {
      // the previous elements are in sorted order
      int k = i;
      for (int j = i - 1; j >=0; --j)
      {
          if (nums[j] <= nums[k])break;
          else {
             swap(nums[j], nums[k--]);
          }
      }
   }
   return;
}

int main()
{
    vector<int> nums = {1, 4, 10, -1, 19, 90000};
    print(nums);
    insertation_sort(nums);
    print(nums);
    return 0;
}
