class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[l]);
                l++;
            }
        }
        
        l=0;
        while(l<nums.size() && nums[l]==0)
            l++;
                
        for(int i=l;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                swap(nums[i],nums[l]);
                l++;
            }
        }
    }
};