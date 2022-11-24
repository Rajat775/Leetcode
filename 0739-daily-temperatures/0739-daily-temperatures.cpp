class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        vector<int>res(temp.size(),0);
        int i=0;
        while(i<temp.size())
        {
            if(!st.empty() && temp[st.top()]>=temp[i])
                st.push(i);
            else{
                while(!st.empty() && temp[st.top()]<temp[i])
                {
                    res[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }
        return res;
    }
};