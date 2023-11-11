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

void add(map<int,int>&m,TreeNode*root){
    if(root == NULL){
        return;
    }
    m[root->val]++;
    add(m,root->left);
    add(m,root->right);
}

public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> m;
        add(m,root);
        int mx = INT_MIN;
        vector<int> ans;
        for(auto p : m){
            if(p.second > mx){
              mx = p.second;
            }
        }

        for(auto p : m){
            if(p.second == mx){
                 ans.push_back(p.first);
            }
        }

        return ans;
        
    }
};