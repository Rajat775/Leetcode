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
    int preOrder;
    unordered_map<int,int>mp;
    
    TreeNode* helper(vector<int>preorder,int left,int right)
    {
        if(left>right) return nullptr;
        int ind = mp[preorder[preOrder]];
        TreeNode *root = new TreeNode(preorder[preOrder++]);
        root->left = helper(preorder,left,ind-1);
        root->right = helper(preorder,ind+1,right);    
        return root;    
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrder=0;
        for(int i=0;i<preorder.size();i++)
            mp[inorder[i]]=i;
        
        return helper(preorder,0,inorder.size()-1);
    }
};