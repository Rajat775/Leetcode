
#define ppi pair<int,pair<int,int>>

class Solution {
public:
  
  int DR[4]={1,0,-1,0};
  int DC[4]={0,1,0,-1};

int trapRainWater(vector<vector<int>>& heightMap) {
     int n=heightMap.size();
     int m=heightMap[0].size();

    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    
    for(int i=0;i<n;i++){           
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
			    pq.push({heightMap[i][j] , {i,j}}) ;
				vis[i][j]=true;
			}
        }
    }
       
    int total=0;
    int minBdht=0;        
    while(!pq.empty())       
    {
        int currHeight = pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        
        minBdht = max( currHeight , minBdht);
        
      
        
        for(int i=0;i<4;i++)
        {
            int newX = x+DR[i];
            int newY = y+DC[i];
            
            if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY] )  // edgecase of bfs
            {
                   pq.push({heightMap[newX][newY] , {newX , newY}});
                   vis[newX][newY]=true;
                   if(heightMap[newX][newY] < minBdht)
                   {
                       total += (minBdht-heightMap[newX][newY]); 
                   }              
            }
            
        }
        
    }
    return total;
}
};