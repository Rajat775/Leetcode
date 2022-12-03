class Solution {
public:
    
    int helper(int cur,vector<int>&dp)
    {   
        if(cur<4)
            return cur;
        if(dp[cur]!=0)
            return dp[cur];
        
        int ans=cur;
        for(int i=1;i*i<=cur;i++)
            ans=min(ans,1+helper(cur-i*i,dp));
        return dp[cur]=ans;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        return helper(n,dp);
    }
};