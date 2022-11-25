class Solution {
public:
    
//     bool check(vector<int>nums,int target,int index,vector<vector<int>>&dp)
//     {
//         if(target==0)
//             return true;
//         if(index==0)
//             return target==nums[0];
        
//         if(dp[index][target]!=-1)
//             return dp[index][target];
        
//         bool nottake = check(nums,target,index-1,dp);
        
//         bool take=false;
        
//         if(target>=nums[index])
//         {
//             take=check(nums,target-nums[index],index-1,dp);
//         }
//         return dp[index][target]=nottake||take;
//     }
    
//     bool canPartition(vector<int>& nums) {
        
//         int sum=0;
//         for(int i:nums)
//             sum+=i;
        
//         if(sum%2)
//             return false;
//         vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
//         return check(nums,sum/2,nums.size()-1,dp);
//     }
    
    bool solution(vector<int>&arr, int target, int index, vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(index==0){
            return (arr[0]==target);
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        //if the index is not selected
        bool notTake = solution(arr, target, index-1, dp);
        
        //if the index is selected
        bool take = false;
        if(target>=arr[index]){
            take = solution(arr, target-arr[index], index-1, dp);
        }
        
        return dp[index][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(auto itr: nums){
            sum += itr;
        }
        if(sum%2==1){
            return false;
        }
        
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solution(nums, target, n-1, dp);
    }
};