#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root== NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            vector<int> tmp_res;
            int q_size = q.size();
            for(int i = 0; i< q_size; i++){
                TreeNode* current = q.front();
                q.pop();
                tmp_res.push_back(current -> val);
                if(current->left != NULL)
                    q.push(current->left);
                if(current->right != NULL)
                    q.push(current->right);
            }
            if(level % 2 != 0) reverse(tmp_res.begin(), tmp_res.end());
            res.push_back(tmp_res);
            level ++;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
