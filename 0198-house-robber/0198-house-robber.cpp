class Solution {
public:
    int rob(vector<int>& nums) {
       
        int ans =0,n=nums.size();
        vector<int>previous(n);
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<i-1;j++)
                temp=max(temp,previous[j]);
            
            previous[i]=nums[i]+temp;
            ans=max(ans,previous[i]);
        }
        return ans;
    }
};