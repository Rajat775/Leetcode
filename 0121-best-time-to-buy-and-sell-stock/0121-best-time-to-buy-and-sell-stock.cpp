class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int m=prices[n-1],profit=0;
        
        for(int i=n-2;i>=0;i--)
        {
            m= max(prices[i],m);
            profit=max(profit,m-prices[i]);
        }
        return profit;
    }
};