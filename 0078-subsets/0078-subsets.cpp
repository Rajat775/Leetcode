class Solution {
public:
    
    void helper(vector<vector<int>>&res,vector<int>&temp,vector<int>nums,int index){
        if(index>=nums.size())
            return;
        temp.push_back(nums[index]);
        res.push_back(temp);
        helper(res,temp,nums,index+1);
        temp.pop_back();
        helper(res,temp,nums,index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()==0)
            return res;
        res.push_back({});
        vector<int>temp;
        helper(res,temp,nums,0);
        return res;
    }
};