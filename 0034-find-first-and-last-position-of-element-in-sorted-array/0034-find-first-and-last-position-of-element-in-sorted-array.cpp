class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=INT_MAX,right=INT_MIN;
        int l=0,r=nums.size()-1;
        
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(nums[m]==target)
                left=min(left,m); 
            if(nums[m]>=target)
                r=m-1;
            else
                l=l+1;
        }
        
        l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(nums[m]==target)
                right=max(right,m);
            if(nums[m]<=target)
                l=m+1;
            else
                r=m-1;
        }
        
        if(left==INT_MAX) return{-1,-1};
        return {left,right};
    }
};