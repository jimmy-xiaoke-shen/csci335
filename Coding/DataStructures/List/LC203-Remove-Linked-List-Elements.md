# LC [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
Solve the problem recursively

```cpp
// Time complexity: O(n)
// Space complexity: O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        if (head -> val == val) return removeElements(head -> next, val);
        auto node = removeElements(head -> next, val);
        head -> next = node;
        return head;
    }
};
```
