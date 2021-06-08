# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
```cpp
/*
time complexity: O(n)
space complexity: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* node, vector<int> &nodes) {
        if (node == nullptr) return;
        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }
    void preorder(TreeNode* node, vector<int> &nodes) {
        if (node == nullptr) return;
        nodes.push_back(node->val);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }
    void postorder(TreeNode* node, vector<int> &nodes) {
        if (node == nullptr) return;
        postorder(node->left, nodes);
        postorder(node->right, nodes);
        nodes.push_back(node->val);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder(root, ret);
        cout << "preorder" <<endl;
        for (auto x: ret) cout<< x<< " ";
        cout << endl;
        ret.clear();
        cout << "postorder" <<endl;
        postorder(root, ret);
        for (auto x: ret) cout<< x<< " ";
         cout << endl;
        ret.clear();
         cout << "inorder" <<endl;
        inorder(root, ret);
        for (auto x: ret) cout<< x<< " ";
        cout << endl;
        return ret;
    }
};
```
