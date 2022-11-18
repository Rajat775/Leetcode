class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int len=0,start=0,end=0;
        for(end=0;end<s.size();end++)
        {
            mp[s[end]]++;
            while(mp[s[end]]>1 && start< end){
                    mp[s[start]]--;
                    if(mp[s[start]]==0)
                        mp.erase(s[start]);
                    start++;
                }
            len=max(end-start+1,len);
        }
        return len;
    }
};