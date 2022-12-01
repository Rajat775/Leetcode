class Solution {
public:
    
    bool canForm(int index,unordered_set<string>st,string s,vector<int>&dp)
    {
        if(index == s.length()) return true;
        if(dp[index]!=-1)
            return dp[index];
        for(int i=index;i<s.size();i++)
        {
            string temp = s.substr(index,i-index+1);
            if(st.find(temp)!=st.end() && canForm(i+1,st,s,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
       unordered_set<string>st(dict.begin(),dict.end());
        vector<int>dp(s.size(),-1);
        return canForm(0,st,s,dp);
    }
};