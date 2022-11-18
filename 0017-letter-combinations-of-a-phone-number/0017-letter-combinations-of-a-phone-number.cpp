class Solution {
public:
    
    void helper(vector<string>&ans,vector<string>dic,string digits,int count,string &temp)
    {
        if(count==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        for(auto i:dic[digits[count]-'0'])
        {
            temp.push_back(i);
            helper(ans,dic,digits,count+1,temp);
            temp.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)
            return ans;
        string temp="";
        vector<string>dic={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(ans,dic,digits,0,temp);
        return ans;
    }
};