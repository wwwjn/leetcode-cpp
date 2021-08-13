#include <iostream>


class Solution{
public:
    // 迭代的解法：超时
    int rob2(TreeNode* root) {

        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int res1 = rob(root->left) + rob(root->right);
        TreeNode* tmp;
        if(root->left != NULL && root->right != NULL){
            tmp = root->left;
            int res_left = rob(tmp->left) + rob(tmp->right);
            tmp = root->right;
            int res_right = rob(tmp->left) + rob(tmp->right);
            return max(res_left + res_right + root->val, res1);
        }
        else if(root->left == NULL){ // 左为空
            tmp = root->right;
            int res_right = rob(tmp->left) + rob(tmp->right);
            return max(res_right + root->val, res1);
        }else{ // 右为空
            tmp = root->left;
            int res_left = rob(tmp->left) + rob(tmp->right);
            return max(res_left + root->val, res1);
        }
    }

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
    class Solution {
    public:
        int rob(TreeNode* root) {
            if(root == NULL)
                return 0;
            dfs(root);
            return max(rob2[root], not_rob[root]);
        }
    private:
        unordered_map <TreeNode*, int> rob2, not_rob;
        void dfs(TreeNode* node){
            if(node == NULL){
                return;
            }
            dfs(node->left);
            dfs(node->right);
            rob2[node] = node->val + not_rob[node->left] + not_rob[node->right];
            not_rob[node] = max(not_rob[node->left], rob2[node->left]) + max(not_rob[node->right], rob2[node->right]);
        }

    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
