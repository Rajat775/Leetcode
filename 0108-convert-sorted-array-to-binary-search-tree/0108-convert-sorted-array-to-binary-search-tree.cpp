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
    
    TreeNode* helper(vector<int>nums,int l,int r)
    {
        if(l>r) return nullptr;
        
        int m = l+(r-l)/2;
        
        TreeNode* left=helper(nums,l,m-1);
        TreeNode* root= new TreeNode(nums[m]);
        root->left=left;
        root->right=helper(nums,m+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        int l=0,r=n-1;
        
        return helper(nums,l,r);
        
    }
};