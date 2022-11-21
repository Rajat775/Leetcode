class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0,cur=0,num;
        for(int i:s)
        {
            if(s.find(i-1)!=s.end())
            continue;
            cur=0;
            num=i;
            while(s.find(num++)!=s.end())
                cur++;
            ans=max(ans,cur);
        }
        return ans;
    }
};