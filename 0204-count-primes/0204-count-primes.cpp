class Solution {
public:
    int countPrimes(int n) {
        vector<bool>dp(n+1,false);
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(dp[i])continue;
            dp[i]=true;
            ans++;
            for(int j=i+i;j<n;j+=i)
                dp[j]=true;
        }
        return ans;
    }
};