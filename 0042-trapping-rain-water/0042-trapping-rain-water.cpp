class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        int maxL=height[0],maxR=height[n-1];
        int l =0 , r=n-1;
        while(l<=r)
        {
            if(height[l]<height[r])
            {
                if(maxL<height[l])
                    maxL=height[l];
                else
                    ans+=(maxL-height[l]);
                l++;
            }
            else{
                if(maxR<height[r])
                    maxR=height[r];
                else
                    ans+=(maxR-height[r]);
                r--;
            }
        }
        return ans;
    }
};