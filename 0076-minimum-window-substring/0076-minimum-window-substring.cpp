class Solution {
public:
    string minWindow(string s, string t) {
        int l=s.size(),r=t.size();
        int st=0,index=-1,length=INT_MAX;
        if(l<r)
            return "";
        int dp1[256]={0};
        int dp2[256]={0};
        
        for(int i=0;i<r;i++)
            dp2[t[i]]++;
        int count=0;
        for(int i=0;i<l;i++)
        {
            dp1[s[i]]++;
            if(dp1[s[i]]<=dp2[s[i]])
            count++;
            
            if(count==r)
            {
                while(dp1[s[st]]>dp2[s[st]] || dp2[s[st]]==0)
                {
                    if(dp1[s[st]]>dp2[s[st]])
                        dp1[s[st]]--;
                    st++;
                }
                if(length>i-st+1)
                {
                    length=i-st+1;
                    index=st;
                }
            }
        }
        if(index==-1)
            return "";
        return s.substr(index,length);
    }
};