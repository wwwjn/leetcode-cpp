#include <iostream>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL && q== NULL) return true;
        else if(!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
