class Solution {
public:
    string longestPalindrome(string s) {
        int l,r,n=s.size();
        int len=1,index=0;
            
        for(int i=0;i<n;i++)
        {
            l=i,r=i;
            while(l>=0 && r<s.size() && s[l--]==s[r++])
            if(len<r-l-1)
            {
                len=r-l-1;
                index=i-(len-1)/2;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l--]==s[r++])
            if(len<r-l-1)
            {
                len=r-l-1;
                index=i-(len-1)/2;
            }
        }
        return s.substr(index,len);
    }
};