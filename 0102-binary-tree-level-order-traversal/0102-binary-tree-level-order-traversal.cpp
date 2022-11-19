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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);
        // res.push_back({root->val});
        while(!q.empty())
        {
            vector<int>temp;
            queue<TreeNode*>p;
            while(!q.empty())
            {
                TreeNode *t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    p.push(t->left);
                if(t->right)
                    p.push(t->right);
            }
            res.push_back(temp);
            q=p;
        }
        return res;
    }
};