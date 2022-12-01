class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=prices.size()-1;i>=1;i--)
        {
            if(prices[i]>prices[i-1])
                ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};