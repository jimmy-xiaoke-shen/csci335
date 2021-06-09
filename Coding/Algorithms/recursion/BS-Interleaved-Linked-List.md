# binarysearch [Interleaved Linked List](https://binarysearch.com/problems/Interleaved-Linked-List)

## Solution 1
```cpp
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1) {
    if (l0 == nullptr && l1 == nullptr) return nullptr;
    if (l0 == nullptr) return l1;
    if (l1 == nullptr) return l0;
    auto node = solve(l1, l0->next);
    l0 -> next = node;
    return l0;
}
```

## solution 2
```cpp
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1) {
    if (l0 == nullptr || l1 == nullptr) return l0? l0: l1;
    auto node = solve(l1, l0->next);
    l0 -> next = node;
    return l0;
}
```
