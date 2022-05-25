#include <iostream>

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode* node, string res, vector<string>& r){
        if(node == NULL) return;
        res += to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            r.push_back(res);
            return;
        }
        else if(node->left == NULL && node-> right != NULL){
            dfs(node->right, res+"->", r);
        }
        else if(node->left != NULL && node->right== NULL){
            dfs(node->left, res+"->", r);
        }else{
            dfs(node->right, res+"->", r);
            dfs(node->left, res+"->", r);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
