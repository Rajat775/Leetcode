class Solution {
public:
    
    static bool compareInterval(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compareInterval);
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(result[result.size()-1][1] < intervals[i][0])
             result.push_back(intervals[i]);
            else {
                int low = min(result[result.size()-1][0],intervals[i][0]);
                int high = max(result[result.size()-1][1],intervals[i][1]);
                result.pop_back();
                result.push_back(vector<int>{low,high});
            }
        }
        return result;
    }
};