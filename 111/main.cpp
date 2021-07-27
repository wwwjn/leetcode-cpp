#include <iostream>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL){
            return minDepth(root->right) + 1;
        }else if(root->right == NULL){
            return minDepth(root->left) + 1;
        }
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        return min(leftHeight, rightHeight) + 1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
