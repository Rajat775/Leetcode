class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(),m=matrix[0].size();
        int cr=0,cl=m-1;
        
        while(cr<n && cl>=0)
        {
            if(matrix[cr][cl] == target)
                return true;
            if(matrix[cr][cl] < target)
                cr++;
            else cl--;
        }
        return false;
    }
};