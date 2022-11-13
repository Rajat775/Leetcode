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
    
    bool valid(TreeNode *t,TreeNode *&prev)
    {
        if(t==nullptr)return true;
        if(!valid(t->left,prev))return false;
        if(prev != nullptr && prev->val >= t->val)
            return false;
        prev=t;
        return valid(t->right,prev);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=nullptr;
        return valid(root,prev);
    }
};