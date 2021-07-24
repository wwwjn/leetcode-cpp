#include <iostream>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root== NULL) return res;
        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);
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
            s.push(tmp_res);
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
