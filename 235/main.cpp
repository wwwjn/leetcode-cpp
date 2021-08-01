#include <iostream>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;

        bool isLeft_p = dfs(root->left, p);
        bool isLeft_q = dfs(root->left, q);
        bool isRight_p = dfs(root->right, p);
        bool isRight_q = dfs(root->right, q);
        if(isLeft_p && isLeft_q){
            // 都在左子树里
            return lowestCommonAncestor(root->left, p, q);
        }else if(isRight_p && isRight_q){
            // 都在右子树中
            return lowestCommonAncestor(root->right, p, q);
        }else{ // 有一个在左子树一个在右子树中
            return root;
        }
    }
    bool dfs(TreeNode* root, TreeNode* p){
        // find if p in the tree of root
        // p is not NULL
        if(root == NULL) return false;
        if(root == p) return true;
        return dfs(root->left, p) || dfs(root->right, p);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
