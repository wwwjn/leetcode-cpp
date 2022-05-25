//
// Created by Jiani Wang on 2021/8/18.
//

// 236题解法，没有利用BST的性质
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL){
        return NULL;
    }
    if(p == root || q == root){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p ,q);
    if(left != NULL && right != NULL){
        return root;
    }else if(left == NULL && right != NULL){
        return right;
    }else if(right == NULL && left != NULL){
        return left;
    }else{
        return NULL;
    }
}