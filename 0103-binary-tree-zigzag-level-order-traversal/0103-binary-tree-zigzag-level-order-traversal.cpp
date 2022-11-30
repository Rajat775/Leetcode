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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr)
            return result;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            vector<int>temp;
            queue<TreeNode*>p;
            while(!q.empty()){
                temp.push_back(q.front()->val);
                if(q.front()->left)
                    p.push(q.front()->left);
                if(q.front()->right)
                    p.push(q.front()->right);
                q.pop();
            }
            if(flag)
                reverse(temp.begin(),temp.end());
            flag=!flag;
            q=p;
            result.push_back(temp);
        }
        return result;
    }
};