# binary search [Sum of Nodes with Even Grandparent Values](https://binarysearch.com/room/No-Homers-Club-VhFa8Vma4Y?questionsetIndex=3)
Solve the problem recursively.

```cpp
/*
jimmy shen
time complexity: O(n)
space complexity: O(n)
*/
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 int ret = 0;
void helper(Tree* node, int grand, int father) {
    if (node == nullptr) return;
    if (grand %2 == 0) {
        ret += node -> val;
    }
    helper(node -> left, father, node->val);
    helper(node -> right, father, node->val);
}
int solve(Tree* root) {
    ret = 0;
    helper(root, -1, -1);
    return ret;
    
}
```
