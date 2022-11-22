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
    
    
    void helper(TreeNode* root,TreeNode *&t)
    {
       if(root==nullptr)
            return ;
        helper(root->right,t);
        helper(root->left,t);
        root->left=nullptr;
        root->right=t;
        t=root;
    }
    
    void flatten(TreeNode* root) {
        TreeNode *temp=nullptr;
        helper(root,temp);
    }
};