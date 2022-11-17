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
    
    void helper(TreeNode *root,int &mode,int &cur_f,int &max_f,vector<int>&res)
    {
        if(root==nullptr)
            return;
        helper(root->left,mode,cur_f,max_f,res);            
        if(root->val != mode)
        {
            cur_f = 1;
            mode = root->val;
        }
        else if(root->val == mode){  
            cur_f++;   
        }
        
        if(cur_f>max_f)
        {
            max_f=cur_f;
            res={mode};
        }else if(cur_f==max_f)
        {
            res.push_back(mode);
        }
        helper(root->right,mode,cur_f,max_f,res);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        // 
        vector<int>res;
        if(root==nullptr)
            return res;
        int mode = -1;
        int max_f = 0;
        int cur_f = 0;
        helper(root,mode,cur_f,max_f,res);
        return res;        
    }
};