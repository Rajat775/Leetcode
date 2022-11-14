class Solution {
public:
    
    bool helper(vector<int>weights,int mid,int days)
    {
        int count =0 ;
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>mid)
            {
                sum=weights[i];
                count++;
            }
            else if(sum==mid)
            {
                count++;
                sum=0;
            }
        }
        if(sum)count++;        
        return count<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        // cout<<low<<" "<<high;
        int ans=low,high=0;
        for(int i:weights)high+=i;
        while(low<=high)
        {
            int mid = high - (high-low)/2;
            if(helper(weights,mid,days))
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};