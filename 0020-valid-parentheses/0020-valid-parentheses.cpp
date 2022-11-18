class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        
        for(char c:s)
        {
            if(c=='(' || c == '[' || c == '{')
                st.push(c);
            else{
                    if(!st.empty())
                    {
                        char t = st.top();
                        if(c == ')' && t!='(') return false;
                        else if(c==']' && t!='[') return false;
                        else if(c=='}' && t!= '{') return false;
                        st.pop();  
                    }else return false;
                }    
        }
        if(st.size()!=0) return false;
        return true;
    }
};