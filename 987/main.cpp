#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        levelorder(root, 0);
        vector<vector<int>> res;
        for(auto item: m){
            res.push_back(item.second);
        }
        return res;
    }
private:
    queue<pair<TreeNode*, int>> record;
    map<int, vector<int>> m;
    void levelorder(TreeNode* node, int level){
        record.push({node, level});
        while(!record.empty()){
            int size = record.size();
            map<int, vector<int>> tmpMap;
            for(int i = 0; i < size; i++){
                auto pair = record.front();
                record.pop();
                TreeNode* cur = pair.first;
                int l = pair.second;
                // insert into map
                if(tmpMap.find(l) == tmpMap.end()){
                    vector<int> tmp;
                    tmp.push_back(cur->val);
                    tmpMap.insert({l, tmp});
                }else{
                    tmpMap[l].push_back(cur->val);
                }

                if(cur->left != NULL){
                    record.push({cur->left, l-1});
                }
                if(cur->right != NULL){
                    record.push({cur->right, l+1});
                }
            }
            for(auto item: tmpMap){
                int v = item.first;
                vector<int> samePosition = item.second;
                sort(samePosition.begin(), samePosition.end());
                if(m.find(v) == m.end()){
                    m.insert({v, samePosition});
                }else{
                    for(auto k: samePosition){
                        m[v].push_back(k);
                    }
                }
            }

        }
    }
};