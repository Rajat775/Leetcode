class Solution {
public:
    
    int findLessOrEqual(int val,vector<vector<int>>& matrix)
    {
        int count =0;
        for(int i=0;i<matrix.size();i++)
            count += upper_bound(matrix[i].begin(),matrix[i].end(),val)-matrix[i].begin();
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0],m=matrix.size(),r=matrix[m-1][m-1];
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int count = findLessOrEqual(mid,matrix);
            if(count<k)
                l=mid+1;
            else 
                r=mid-1;
        }
        return l;
    }
};