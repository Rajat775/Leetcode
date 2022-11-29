class Solution {
public:
    // #define ll long long int 
    
    int mySqrt(int x) {
          if(x==0 || x==1)
              return x;
          int l=1,r=x/2,ans;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                if(mid<=(x/mid))
                {   
                    ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
		return ans;
    }
};