class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        if(nums[0]==0)return false;
        int steps=nums[0],maxReach=nums[0];
        // int jump=1;
        int i=1;
        
        while(i<nums.size())
        {
            if(i==nums.size()-1)
                return true;
            steps--;
            maxReach=max(maxReach,i+nums[i]);
            if(steps==0)
            {
                // jump++;
                if(i>=maxReach)
                return false;
                steps=maxReach-i;
            }
            i++;
        }
        return true;
    }
};