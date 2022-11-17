class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int left=0,right=0,res=INT_MIN;
        unordered_map<char,int>mp;
        for(right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                    mp.erase(s[left]);
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};