class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==temp[temp.size()-1])
                continue;
            temp.push_back(nums[i]);
        }
        int res=1;
        int l = 0,i;
        for(i=1;i<temp.size();i++)
        {
            if(temp[i]!=temp[i-1]+1)
            {
                res = max(res,i-l);
                l=i;
            }
            
        }
        res=max(res,i-l);
        return res;
    }
};