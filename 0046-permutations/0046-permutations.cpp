class Solution {
public:
    
    void permutation(vector<int>nums,vector<int>&ds,vector<vector<int>>&ans,unordered_map<int,int>&mp)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>0)
            {
                mp[nums[i]]--;
                    ds.push_back(nums[i]);
               permutation(nums,ds,ans,mp);     
               mp[nums[i]]++;     
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i:nums){
            m[i]++;
        }
        permutation(nums,ds,ans,m);
        return ans;
        
    }
};