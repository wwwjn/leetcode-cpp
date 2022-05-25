#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        Node* dummyHead = new Node(0, NULL, head, NULL);
        dfs(dummyHead, head);

        dummyHead->next->prev = NULL;
        return dummyHead->next;
    }
    Node* dfs(Node* prev, Node* cur){
        // return the tail of flatten list
        if(cur == NULL) return prev;
        cur->prev = prev;
        prev->next=cur;

        Node* tempNext = cur->next;

        Node* tail = dfs(cur, cur->child);
        cur->child = NULL;
        return dfs(tail, tempNext);
    }
};