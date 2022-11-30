class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<int>dx={1,1,0,-1,-1,-1,0,1};
        vector<int>dy={0,1,1,1,0,-1,-1,-1};
        int n = board.size() , m = board[0].size();
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx>=0 && nx < n && ny >=0 && ny<m && (board[nx][ny]==1 || board[nx][ny]==2))
                        count++;
                }
                if(board[i][j]==1){
                    if(count<2 || count>3)
                        board[i][j]=2;
                }else {
                    if(count==3)
                        board[i][j]=3;
                }
                
            }
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2)
                    board[i][j]=0;
                if(board[i][j]==3)
                    board[i][j]=1;
            }
    }
};