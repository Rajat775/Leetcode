class Solution {
public:
    
    bool match(int st,string m,string hay)
    {
    
        int l=0;
        while(l<m.size() && st<hay.size())
        {
            if(hay[st]!=m[l])
                return false;
            l++;
            st++;
        }
        if(l==m.size())
            return true;
        return false;
    }
    
    int strStr(string h, string s) {
        
        if(s.size()>h.size())
        return -1;
        // int index=-1;
        for(int i=0;i<h.size();i++)
        {
            if(h[i]==s[0])
            {
                if(match(i,s,h))
                    return i;
            }
        }
        return -1;
    }
};