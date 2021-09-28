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
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* head2 = new Node(head->val);
        unordered_map<Node*, Node*> old2New;
        old2New.insert({head, head2});

        Node* cur = head->next;
        Node* cur2 = head2;
        while(cur!= NULL){
            Node* newCur = new Node(cur->val);
            cur2->next = newCur;
            old2New.insert({cur, newCur});
            cur = cur->next;
            cur2 = cur2->next;
        }

        cur = head;
        while(cur!=NULL){
            Node* r = cur->random;
            if(r!= NULL){
                Node* newRdm = old2New[r];
                Node* newCur = old2New[cur];
                newCur->random = newRdm;
            }
            cur = cur->next;
        }
        return head2;
    }
};