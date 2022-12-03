class Solution {
public:
    
    int helper(string s,int k,int cur)
    {
        unordered_map<char,int>mp;
        int atleastK=0,start=0;
        int maxU=0;
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
                maxU++;
            mp[s[i]]++;
            if(mp[s[i]]==k)
                atleastK++;
            
            // if(maxU>cur)
            // {
                while(maxU>cur)
                {
                    if(mp[s[start]]==k)
                        atleastK--;
                    mp[s[start]]--;
                    if(mp[s[start]]==0)
                    {
                        maxU--;
                        mp.erase(mp.find(s[start]));
                    }
                    start++;
                }
            // }
            if(atleastK==maxU)
            len = max(len,i-start+1);
        }
        return len;
    }
    
    
    int longestSubstring(string s, int k) {
        unordered_set<char>st(s.begin(),s.end());
        cout<<st.size()<<" ";
        int maxAll=-1;
        for(int i=1;i<=st.size();i++)
            maxAll=max(maxAll,helper(s,k,i));
        return maxAll;
    }
};