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


map<int,vector<TreeNode*>> m;
vector<TreeNode*> helper(int n){
  
     if(n % 2 == 0 ){
         return {};
     }

     if(n == 1){
         TreeNode* node = new TreeNode(0);
         return {node};
     }

     if(m.find(n) != m.end()){
         return m[n];
     }

    vector<TreeNode*>ans;
    
    for(int i = 1; i < n; i = i + 2){
        vector<TreeNode*> left = helper(i);
        vector<TreeNode*> right = helper(n-i-1);
        for(TreeNode* l : left){
            for(TreeNode* r : right){
                TreeNode *root = new TreeNode();
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }

    return m[n] = ans;

}


public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        return helper(n);
        
    }
};