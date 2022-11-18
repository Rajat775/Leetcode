class Solution {
public:
    
    void helper(vector<string>&ans,string &temp,int left,int right,int n)
    {
        if(left>n)return;
        
        if(right==n)
        {   
            ans.push_back(temp);
            return;
        }
        
        if(left<n)
        {   temp+='(';
            helper(ans,temp,left+1,right,n);
            temp.pop_back();
        }
        
        if(right<left)
        {
            temp+=')';
            helper(ans,temp,left,right+1,n);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int left=0,right=0;
        string temp="";
        vector<string>ans;
        helper(ans,temp,left,right,n);
        return ans;
    }
};