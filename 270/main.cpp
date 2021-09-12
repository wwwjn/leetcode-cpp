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
    int closestValue(TreeNode* root, double target) {
        double diff = abs(root->val - target);
        int res = root->val;
        while(root!= NULL){
            if((double)abs(root->val - target) < diff){
                diff = (double) abs(root->val - target);
                res = root->val;
            }
            if(target >= root->val){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return res;
    }
};
