#include <iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        queue<Node*> record;
        record.push(root);
        while(!record.empty()){
            int m = record.size();
            Node* ptr = record.front();
            record.pop();
            if(ptr->left != NULL)
                record.push(ptr->left);
            if(ptr->right != NULL){
                record.push(ptr->right);
            }
            for(int i = 1; i< m; i++){
                Node* temp = record.front();
                record.pop();
                ptr->next = temp;
                if(temp->left != NULL)
                    record.push(temp->left);
                if(temp->right != NULL){
                    record.push(temp->right);
                }
                ptr = ptr->next;
            }
        }
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
