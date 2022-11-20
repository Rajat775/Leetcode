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
    
    int helper(TreeNode*t,int k,int &r)
    {
       if(t==nullptr) return -1;
        int left = helper(t->left,k,r);
            if(left!=-1) return left;
        r++;
        if(r==k)
            return t->val;
        return helper(t->right,k,r);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int r=0;
        return helper(root,k,r);
    }
};