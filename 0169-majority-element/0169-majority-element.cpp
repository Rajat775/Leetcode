class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mj=nums[0],curq=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==mj)
                curq++;
            else{
                curq--;
            }
            if(curq==0)
            {
                mj=nums[i];
                curq=1;
            }
        }
        return mj;
    }
};