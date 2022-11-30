class Solution {
public:
    
    static bool cmp(int &a, int &b) {
        string s = to_string(a), t = to_string(b);
        int i = 0, j = 0;
        while(i < s.size() || j < t.size()) {
            if(s[i] == t[j]) i++, j++;
            else break;
        }
        if(i < s.size() && j < t.size())
            return s[i] > t[j];
        return s+t > t+s;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(count(nums.begin(), nums.end(), 0) == nums.size()) 
            return "0";
        string ans = "";
        for(auto i : nums)
            ans += to_string(i);
        return ans;
    }
};