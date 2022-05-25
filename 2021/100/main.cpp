#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL && q!= NULL) return false;
        else if(p!= NULL && q == NULL) return false;
        if(p->val == q->val){
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
            return left && right;
        }
        else return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
