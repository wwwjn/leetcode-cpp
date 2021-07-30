#include <iostream>

// 这个题可以设置一个类内的变量vector<int> path来储存，并push_back进全局变量res。
// 避免最后一次反转

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res = needToReverse(root, targetSum);

        for(int i = 0; i < res.size(); i++){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    vector<vector<int>> needToReverse(TreeNode* root, int targetSum){
        vector<vector<int>> res;
        if(root == NULL) return res;
        if(root->left == NULL && root->right == NULL){ // leaf node
            if(root->val == targetSum){
                vector<int> tmp;
                tmp.push_back(root->val);
                res.push_back(tmp);
                return res;
            }
        }
        else{  // not leaf

            vector<vector<int>> left = needToReverse(root->left, targetSum - (root->val));
            for(int i = 0; i < left.size(); i++){
                left[i].push_back(root->val);
                res.push_back(left[i]);
            }

            vector<vector<int>> right = needToReverse(root->right, targetSum-(root->val));
            for(int i=0; i< right.size(); i++){
                right[i].push_back(root->val); // 应该改为从前面插入
                res.push_back(right[i]);
            }
        }

        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
