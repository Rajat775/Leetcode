class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int>ans;
        vector<vector<int>>dp(numCourses);
        for(int i=0;i<pre.size();i++)
            dp[pre[i][1]].push_back(pre[i][0]);
        
        vector<int>count(numCourses,0);
        
        for(int i=0;i<pre.size();i++)
            count[pre[i][0]]++;
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
            if(count[i]==0)
                q.push(i);
        
        while(!q.empty()){
            int src=q.front();
            q.pop();
            
            ans.push_back(src);
            for(auto i:dp[src])
            {
                count[i]--;
                if(count[i]==0)
                    q.push(i);
            }
        }
        return ans.size()==numCourses ? ans : vector<int>{};
    }
};