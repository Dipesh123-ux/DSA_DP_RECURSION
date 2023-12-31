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


void converToString(TreeNode* root,string &ans){
    if(root == NULL){
        return;
    }


  
    ans += to_string(root->val);

    if(root->left || root->right){
        ans += "(";
        converToString(root->left,ans);
        ans += ")";
    }

    if(root->right){
        ans += "(";
        converToString(root->right,ans);
        ans += ")";
    }
  
    
}

public:
    string tree2str(TreeNode* root) {
        string ans = "";
        converToString(root,ans);
        return ans;
    }
};