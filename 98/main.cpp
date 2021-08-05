#include <iostream>


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return bfs(root, LONG_MIN, LONG_MAX);
    }
    bool bfs(TreeNode* root, long lower, long upper){
        // the value in (lower, upper)
        if(root == NULL) return true;
        if(root->val > lower && root->val < upper)
            return bfs(root->left, lower, root->val) && bfs(root->right, root->val, upper);
        else
            return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
