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
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> record; // record the first node's path to root;
        record.insert(p);
        while(p->parent != NULL){
            record.insert(p->parent);
            p = p->parent;
        }
        if(record.find(q) != record.end()){
            return q;
        }else{
            while(q->parent != NULL){
                if(record.find(q->parent) != record.end()){
                    return q->parent;
                }else{
                    q = q->parent;
                }
            }
            return NULL;
        }
    }
};