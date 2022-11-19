class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;
        
        int n=0,m=matrix.size()-1,p=0,q=matrix[0].size()-1;
        
        while(n<=m && p<=q)
        {
            for(int i=p;i<=q;i++)   
                res.push_back(matrix[n][i]);
            n++;
            
            for(int i=n;i<=m;i++)
                res.push_back(matrix[i][q]);
            q--;
            
            if(n<=m && p<=q)
            {
                for(int i=q;i>=p;i--)
                    res.push_back(matrix[m][i]);
                m--;
                
                for(int i=m;i>=n;i--)
                    res.push_back(matrix[i][p]);
                p++;    
            }
            
        }
        return res;
    }
};