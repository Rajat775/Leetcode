class Solution {
public:
    
    void helper(vector<int>candidates,int sum,vector<int>&res,int index,vector<vector<int>>&ans)
    {
        if(sum<0)
            return;
        if(sum==0)
        {
            ans.push_back(res);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            res.push_back(candidates[i]);
            helper(candidates,sum-candidates[i],res,i,ans);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int>temp;
        vector<vector<int>>res;
        helper(candidates,target,temp,0,res);
        return res;
    }
};