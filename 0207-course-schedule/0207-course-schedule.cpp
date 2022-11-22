class Solution {
public:

    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
            
        vector<int>dependent(num,0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                dependent[adj[i][j]]++;
            }
        }
        
        // for(auto i:dependent)
        //     cout<<i<<" ";
        queue<int>q;
        for(int i=0;i<dependent.size();i++)
            if(dependent[i]==0)
                q.push(i);
        
        vector<int>ans;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto k:adj[t])
            {
                dependent[k]--;
                if(dependent[k]==0)
                    q.push(k);
            }
        }
        return ans.size()==num;
    }
};