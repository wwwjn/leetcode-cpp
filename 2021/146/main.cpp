#include <iostream>
// Bidirectional Linkedlist
// 单向链表不能在O(1)时间内删除
struct DLinkedNode{  // store the key-value
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(){
        key = 0;
        val = 0;
        prev = NULL;
        next = NULL;
    }
    DLinkedNode(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }

};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> record; // (key, DlinkedNode)
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int cap;
public:

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new DLinkedNode();  // dummy head;
        tail = new DLinkedNode();  // dummy tail;
        tail -> prev = head;
        head -> next = tail;
    }

    int get(int key) {
        if(record.find(key) == record.end()){
            return -1;
        }else{
            DLinkedNode* node = record[key];
            moveToHead(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        if(record.find(key) == record.end()){  // can not find
            DLinkedNode* node = new DLinkedNode(key, value);
            addToHead(node);
            record.insert(make_pair(key, node));
            size++;
            if(size > cap){  // size == cap
                DLinkedNode* delNode = delFromTail();
                record.erase(delNode->key);
                delete delNode;
                size--;
            }
        }else{ // update value
            DLinkedNode* node = record[key];
            node->val = value;
            moveToHead(node);
        }
    }
    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    DLinkedNode* delFromTail(){
        DLinkedNode* delNode = tail->prev;
        delNode->prev->next = tail;
        tail->prev = delNode->prev;
        return delNode;
    }
    void moveToHead(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
