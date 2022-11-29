class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        if(s.size()==1)
            return mp[s[0]];
        int sum=mp[s[0]],total=0,i=1;
        while(i<s.size())
        {
            if(s[i]==s[i-1])
                sum+=mp[s[i]];
            else if(mp[s[i]] > mp[s[i-1]]) {
                total+= (mp[s[i]] - sum);   
                sum=0;
            }
            else{
                total+=sum;
                sum = mp[s[i]];
            }
            i++;
        }
        total+=sum;
        return total;
    }
};