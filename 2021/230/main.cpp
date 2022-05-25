#include <iostream>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int res;
        dfs(root, count, res);
        return res;
    }
    void dfs(TreeNode* root, int& count, int& res){
        // count: still left count to reach k
        if(root == NULL) return;
        dfs(root->left, count, res);
        count --;
        if(count == 0 && root != NULL){
            res = root->val;
            return;
        }
        dfs(root->right, count, res);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
