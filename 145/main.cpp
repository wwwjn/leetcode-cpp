#include <iostream>
#include <vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    void postorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
