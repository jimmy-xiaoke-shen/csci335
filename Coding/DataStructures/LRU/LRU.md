# [146. LRU Cache](https://leetcode.com/problems/lru-cache/)

```cpp
/*
functions get O(1)
nodes {key: node's position}, check whether key exists, if yes, you can return the value
if not, return -1

*/


// double linked list node
struct Node {
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
};


class LRUCache {
public:
    int size = 0;
    int capacity;
    unordered_map<int, Node*> nodes;
    Node* head;
    Node* tail;
    LRUCache(int capacity): capacity(capacity) {
        // initialize a dummy head and tail;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        // at the beginning, make them connect to each other
        head -> next = tail; tail -> prev = head;
        head -> prev = tail; tail -> next = head; 
        
    }
    
    int get(int key) {
        // check whether the key exist
        // Not found
        if (nodes.find(key) == nodes.end()) return -1;
        // key can be found
        auto node = nodes[key];
        // should update this node
        update(node);
        return node -> val;  
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        // key exist, we should update the node's position and val
        if (nodes.find(key) != nodes.end()){
            auto node = nodes[key];
            update(node);
            node -> val = value;
            return;
        }
        // key does not exist? insert
        // reach the capacity? if you reach the capacity, delete the least recently used node and put else, just put
        if (size == capacity){
            // delect the lease recently used node
            auto leaseRUNode = tail -> prev;
            evict(leaseRUNode);
        }
        Node* newNode = new Node(key, value);
        moveToHead(newNode);
        nodes[key] = newNode;
    }
private:
    // pop an element
    // suppose we have A, B, C nodes and we wannt to pop B.
    void pop(Node* node){
        auto B = node;
        auto A = B -> prev;
        auto C = B -> next;
        A -> next = C;
        C -> prev = A;
        size--;
    }
    // move the node to head
    void moveToHead(Node* node){
       // A C, we are going to put B between  A and C
       auto B = node;
       auto A = head;
       auto C = head -> next;
        A -> next = B;
        B -> prev = A;
        B -> next = C;
        C -> prev = B; 
        size++;
    }
    void evict(Node* node){
        pop(node);
        nodes.erase(node -> key);
        delete node;
    }
    // remove an element and put it in the front.
    void update(Node* node){
        pop(node);
        moveToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
