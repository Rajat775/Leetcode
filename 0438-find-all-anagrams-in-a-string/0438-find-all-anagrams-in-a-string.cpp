class Solution {
public:
    
    bool match(int count1[],int count2[])
    {
        for(int i=0;i<26;i++)
            if(count1[i]!=count2[i])
                return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int l1=s.size(),l2=p.size();
        
        if(l2>l1)
            return {};
        
        int count1[26]={0};
        int count2[26]={0};
        for(int i=0;i<p.size();i++)
            count2[p[i]-'a']++;
        
        for(int i=0;i<p.size();i++)
            count1[s[i]-'a']++;
        vector<int>ans;
        if(match(count1,count2))
            ans.push_back(0);
        
        for(int i=p.size();i<s.size();i++)
        {
            count1[s[i]-'a']++;
            count1[s[i-p.size()]-'a']--;
            if(match(count1,count2))
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};