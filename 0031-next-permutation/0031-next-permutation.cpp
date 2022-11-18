class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;    
    
        while(j>0 && nums[j]<=nums[j-1])
            j--;
        
        if(j==0)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            int sm = j-1;
            int index = j;
            for(int k=j+1;k<nums.size();k++)
            {
                if(nums[k]>nums[sm] && nums[k]<=nums[index])
                    index=k;
            }
            swap(nums[sm],nums[index]);

            reverse(nums.begin()+sm+1,nums.end());
        }
    }
};