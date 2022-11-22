class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(2,vector<int>(m+1,0));
        bool b;
        for(int i=0;i<=n;i++)
        {   b = i & 1;
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[b][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[b][j]=dp[1-b][j-1]+1;
                else 
                    dp[b][j]=max(dp[1-b][j],dp[b][j-1]);
            }
        }
        return dp[b][m];
    }
};