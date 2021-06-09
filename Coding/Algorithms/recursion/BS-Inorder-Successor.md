# binarysearch [Inorder Successor](https://binarysearch.com/problems/Inorder-Successor)

## Solution 1
```cpp
// time complexity: O(n)
// space complexity: O(n)
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 void helper(vector<int>& values, Tree* node){
     if (node == nullptr) return;
     helper(values, node -> left);
     values.push_back(node -> val);
     helper(values, node -> right);
 }
int solve(Tree* root, int t) {
    vector<int> ret;
    helper(ret, root);
    auto it = upper_bound(ret.begin(), ret.end(), t);
    return *it;
}
```

## Solution 2
```cpp
// time complexity O(h)
// space complexity O(h)
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, int t) {
    if (root == nullptr) return INT_MAX;
    if (root -> val <= t) return solve(root -> right, t);
    return min(root -> val, solve(root -> left, t));
}
```
