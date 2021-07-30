#include <iostream>



class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 前3个if处理特殊情况
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        else if(root->left == NULL && root->right != NULL)
            return sumOfLeftLeaves(root->right);
        else if(root->left->left == NULL && root->left->right == NULL)
            return sumOfLeftLeaves(root->right) + root->left->val;
        else{
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
