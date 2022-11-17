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
    vector<int>result;
    int maxFreq=0,current=0,freq=0;
    
    vector<int> findMode(TreeNode* root) {
        
    //Base condition
       if(!root)
            return result;
    
    //Traverse left sub tree    
       findMode(root->left);
        
    //Upon visiting a node
       if(current!=root->val)
       {
           freq=1;
           current=root->val;
       }

       else if(current==root->val)
       {
         freq++;   
       }
       if(freq>maxFreq)
       {
           maxFreq=freq;
           result={current};
           
       }
        else if(freq==maxFreq)
        {
            result.push_back(current);
        }
        
    //Traverse right subtree
       findMode(root->right);
        
         return result;
    }
   
};
//     void helper(TreeNode *root,int &mode,int cur_f,int max_f,vector<int>&res)
//     {
//         if(root==nullptr)
//             return;
        
//         helper(root->left,mode,cur_f,max_f,res);                    
//         if(root->val == mode)
//         {
//             cur_f++;
//         }
//         else if(curr != mode){  
//             cur_f = 1;
//             mode = root->val;
//         }
        
//         if(cur_f>max_f)
//         {
//             max_f=cur_f;
//             res={mode};
//         }else if(cur_f==max_f)
//         {
//             res.push_back(mode);
//         }
//         helper(root->right,mode,cur_f,max_f,res);
//     }
    
//     vector<int> findMode(TreeNode* root) {
//         // 
//         vector<int>res;
//         if(root==nullptr)
//             return res;
//         int mode = -1;
//         int max_f = 0;
        
//         helper(root,mode,0,0,res);
//         return res;        
//     }
// };