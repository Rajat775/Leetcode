class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size()<=1)
            return nums;
        int c1=0,c2=0,mj1=INT_MAX,mj2=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mj1)
            {
                c1++;
            }else if(nums[i]==mj2)
            {
                c2++;
            }
            else if(c1==0){
                mj1=nums[i];
                c1=1;
            }else if(c2==0)
            {
                mj2=nums[i];
                c2=1;
            }else  {
                c1--;c2--;
            }
            
        }
        c1=0,c2=0;
        for(int i:nums)
        {
            if(i==mj1)c1++;
            if(i==mj2)c2++;
        }
        
        vector<int>ans;
        if(mj1!=mj2){
        if(c1>floor(nums.size()/3))ans.push_back(mj1);
        if(c2>floor(nums.size()/3))ans.push_back(mj2);
        }
        else{
                    if(c1>floor(nums.size()/3))ans.push_back(mj1);
        }
        return ans;
    }
};