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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int res = 0;
    int helper(Node* node){
        // return the longest way
        if(node == NULL) return 0;
        // pass throught the node
        int first = 0;  // find max two
        int second = 0;
        vector<Node*> children = node->children;
        for(int i = 0; i < children.size(); i++){
            int tmp = helper(children[i]);
            if(tmp > first){
                second = first;
                first = tmp;
            }else if(tmp > second){
                second = tmp;
            }
        }
        res = max(res, first + second);
        return first +1;
    }
public:
    int diameter(Node* root) {
        helper(root);
        return res;
    }
}