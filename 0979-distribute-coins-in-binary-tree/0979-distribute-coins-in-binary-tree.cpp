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
    
    int helper(int &res,TreeNode*root)
    {
        if(root==nullptr)       // inorder traversal
            return 0;
        
        int left = helper(res,root->left);
            
        int right = helper(res,root->right);    
        
        res += abs(left) + abs(right);
        
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        int ans=0 ;
        
        helper(ans,root);     
        return ans ;
    }
};