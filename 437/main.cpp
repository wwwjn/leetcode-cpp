#include <iostream>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root == NULL) return 0;
        // 处理root结点在path上的情况
        count += findPath(root, targetSum);
        // 处理root结点不在path上的情况
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
    // 解决node在这条路径上的情况
    int findPath(TreeNode* root, int targetSum){
        if(root == NULL) return 0;
        int res = 0;

        // 路径的结尾不一定在叶子结点上
        if(root->val == targetSum){
            res++;
        }
        res += findPath(root->left, targetSum - (root->val));
        res += findPath(root->right, targetSum - (root->val));
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
