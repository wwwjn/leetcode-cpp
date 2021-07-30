#include <iostream>
using namespace std;

class Solution{
public:
    int sum = 0;
    int num = 0;  // the num of this path
    int sumNumbers(TreeNode* root){
        if(root == NULL) return 0;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root,int number){
        // return the sum of
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            number += root->val;
            sum += number;
        }else{
            number += root->val;
            number *= 10;
            dfs(root->left, number);
            dfs(root->right, number);
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
