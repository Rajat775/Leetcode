class Solution {
public:
    
    bool helper(vector<vector<bool>>&vis,vector<vector<char>>& board, string word,int n,int m,int i,int j,int index)
    {
        if(index==word.size())
            return true;
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        if(vis[i][j]) return false;
        if(word[index]!=board[i][j])
            return false;
        vis[i][j]=true;
        
        if(helper(vis,board,word,n,m,i-1,j,index+1))
            return true;
        if(helper(vis,board,word,n,m,i+1,j,index+1))
            return true;
        if(helper(vis,board,word,n,m,i,j-1,index+1))
            return true;
        if(helper(vis,board,word,n,m,i,j+1,index+1))
            return true;
        
        vis[i][j]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size(),m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && helper(vis,board,word,n,m,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};