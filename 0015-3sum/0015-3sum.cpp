class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l,r;
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    
                    while(l<nums.size()-1 && nums[l]==nums[l+1])
                        l++;
                    
                    while(r>0 && nums[r]==nums[r-1])
                        r--;
                    l++;r--;
                }else if(nums[i]+nums[l]+nums[r]>0)
                {
                    r--;
                }
                else{
                    l++;
                }
                
            }
        }
        return res;
    }
};