#include <iostream>

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return makeBST(nums, 0, nums.size());
    }
    TreeNode* makeBST(vector<int>& nums, int begin, int end){
        // make nums[begin, end) to a BST
        if(begin >= end)
            return NULL;
        if(end == begin + 1){ // only one node
            return new TreeNode(nums[begin]);
        }
        else{
            int mid = (begin + end) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = makeBST(nums, begin, mid);
            root->right = makeBST(nums, mid+1, end);
            return root;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
