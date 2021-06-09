# Binary Search [Longest Tree Sum Path From Root to Leaf](https://binarysearch.com/problems/Longest-Tree-Sum-Path-From-Root-to-Leaf)


```cpp
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 int sum = 0, len = 0;
 void helper(Tree* node, int curr_sum, int curr_len) {
     if (node == nullptr){
         if (curr_len > len){
             len = curr_len;
             sum = curr_sum;
         } 
         if (curr_len == len && curr_sum > sum) {
             sum = curr_sum;
         }
        return;
     }
     helper(node -> left,  curr_sum +  (node -> val), curr_len + 1);
     helper(node -> right, curr_sum + (node -> val), curr_len + 1);
 }
 
int solve(Tree* root) {
    sum = 0;
    len = 0;
    helper(root, 0, 0);
    return sum;
    
}
```
