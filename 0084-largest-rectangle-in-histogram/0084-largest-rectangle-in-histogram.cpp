class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int area =0 ;
        stack<int>st;
        int i=0;
        while(i<heights.size())
        {
            if(st.empty() || heights[st.top()]<=heights[i])
                st.push(i++);
            else{
                int h = st.top();st.pop();
                int temp = heights[h]*(st.empty() ? i : i-st.top()-1);
                area=max(area,temp);
            }
        }
        
        while(!st.empty()){
                int h = st.top();st.pop();
                int temp = heights[h]*(st.empty() ? i : i-st.top()-1);
                area=max(area,temp);
        }
        
        return area;
    }
};