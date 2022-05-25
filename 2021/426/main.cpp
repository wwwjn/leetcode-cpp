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

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node *head = NULL, *pre = NULL;
        inorder(root, pre, head);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void inorder(Node* root, Node*& pre, Node*& head){
        // root: current node;
        if(root == NULL) return;
        Node* leftChild = root->left;
        Node* rightChild = root->right;
        inorder(leftChild, pre, head);
        if(head == NULL){
            pre = root;
            head = root;
        }else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        inorder(rightChild, pre, head);
    }
};