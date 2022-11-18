class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,0);
        if(n<=3)
            return n;
        int first = 1,second = 2;
        int res=0;
        // dp[1]=1;
        // dp[2]=2;
        for(int i=3;i<=n;i++){
            res = first + second;
            first = second;
            second = res;
            // dp[i]=dp[i-1]+dp[i-2];
        }
        return res;
    }
};