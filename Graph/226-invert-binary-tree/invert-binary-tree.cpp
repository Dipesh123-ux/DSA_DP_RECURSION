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

void swapFun(TreeNode *root){
   if(root != NULL){
    swap(root->left,root->right);
    swapFun(root->left);
    swapFun(root->right);
   }
}

public:
    TreeNode* invertTree(TreeNode* root) {
        swapFun(root);
        return root;
    }
};