class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>res;
        
        sort(intervals.begin(),intervals.end());
        
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(res[res.size()-1][1]<intervals[i][0])
                res.push_back(intervals[i]);
            else
            {   
                int m = min(res[res.size()-1][0],intervals[i][0]);
                    int n = max(res[res.size()-1][1],intervals[i][1]);
                res.pop_back();
                res.push_back({m,n});    
            }
        }
        return res;
    }
};