class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        int maxLeft=height[0],maxRight=height[n-1];
        int l=0,r=n-1,sum=0;
        while(l<=r)
        {
            if(maxLeft<maxRight)
            {
                if(maxLeft<height[l])
                {
                    maxLeft=height[l];
                }
                else{
                    sum+=(maxLeft-height[l++]);
                }
            }
            else{
                if(maxRight<height[r])
                    maxRight=height[r];
                else
                    sum+=(maxRight-height[r--]);
            }
        }
        return sum;
    }
};