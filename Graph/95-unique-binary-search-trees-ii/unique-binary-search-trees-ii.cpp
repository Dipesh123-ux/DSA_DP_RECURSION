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

vector<TreeNode*> helper(int s,int e){
    if(s > e){
        vector<TreeNode*> v;
        v.push_back(NULL);
        return v;
    }

    vector<TreeNode*>ans;
    
    for(int i = s; i <= e; i++){
        vector<TreeNode*> left = helper(s,i-1);
        vector<TreeNode*> right = helper(i+1,e);
        for(TreeNode* l : left){
            for(TreeNode* r : right){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }

    return ans;

}

    vector<TreeNode*> generateTrees(int n) {
        
        return helper(1,n);
    }
};