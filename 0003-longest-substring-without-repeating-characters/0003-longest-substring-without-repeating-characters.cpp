class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)return s.size();
        vector<bool>visited(256,false);
        int i=0,j=0,result=0;
        while(i<s.size())
        {
            if(visited[s[i]]==false)
                visited[s[i]]=true;
            else{
                    result=max(result,i-j);
                while(s[j]!=s[i])
                {
                    visited[s[j]]=false;
                    j++;
                }
                j++;
            }
            i++;
        }
        result=max(result,i-j);
        return result;
    }
};