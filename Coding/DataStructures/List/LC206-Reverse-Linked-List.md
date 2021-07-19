# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)  
This is a classical problem. We can solve it iteratively or recursively
## iteratively
```cpp
// time complexity: O(n)
// space complexity: O(1)
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next ;
        while (curr){
            next = curr -> next;
            //reverse operation;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```

## recursively
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        auto node =  reverseList(head -> next);
        auto reversed_list_tail = head-> next;
        reversed_list_tail -> next = head;
        head -> next = nullptr;
        return node;
    }
};
```
