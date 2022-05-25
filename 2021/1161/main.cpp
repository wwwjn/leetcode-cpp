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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int index = 0;
        int maxIdx = 0;
        while(!q.empty()){
            index ++;
            int s = q.size();
            int sum = 0;
            for(int i = 0; i< s; i++){
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                maxIdx = index;
            }
        }
        return maxIdx;
    }
};