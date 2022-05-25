#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder2(TreeNode* root) {
        queue<pair<TreeNode*, int>> s;
        vector<vector<int>> res;
        if(root== NULL) return res;
        s.push(make_pair(root, 0));
        int cur_level = 0;
        vector<int> tmp_res;
        while(!s.empty()){
            auto p = s.front();
            TreeNode* current = p.first;
            int level = p.second;
            s.pop();
            if(level != cur_level){
                res.push_back(tmp_res);
                tmp_res.clear();
                tmp_res.push_back(current->val);
                cur_level = level;
            }else{
                tmp_res.push_back(current->val);
            }
            if(current->left != NULL)
                s.push(make_pair(current->left, level + 1));
            if(current -> right != NULL)
                s.push(make_pair(current-> right, level + 1));

        }
        if(tmp_res.size() != 0) res.push_back(tmp_res);
        return res;

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            vector<int> tmp_res;
            for(int i = 0; i < q_size; i++){
                TreeNode* current = q.front();
                q.pop();
                tmp_res.push_back(current -> val);
                if(current -> left != NULL)
                    q.push(current->left);
                if(current -> right != NULL){
                    q.push(current-> right);
                }
            }
            res.push_back(tmp_res);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
