#include <iostream>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        if(left == NULL && right != NULL) // 都在右侧
            return right;
        else if(left != NULL && right == NULL)  // 都在左侧
            return left;
        else if(left != NULL && right != NULL) // 一个在左侧一个在右侧
            return root;
        else
            return NULL;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
