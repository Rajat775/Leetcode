class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int i=0;
        
        while(i<nums.size())
        {
            while(i>0 && i<nums.size() && nums[i]==nums[i-1])
                i++;
            if(i<nums.size())
                nums[j++]=nums[i];
            i++;
        }
        return j;
    }
};