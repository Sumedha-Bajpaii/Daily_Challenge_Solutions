class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0] != 0)
            return -1;
        
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = 1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    // if(i==0 && j==0)
                    //     continue;
                    if(x+i<0 or x+i>=m or y+j<0 or y+j>=n)
                        continue;
                    if(grid[x+i][y+j]==1)
                        continue;
                    if(dist[x+i][y+j] > dist[x][y]+1){
                        dist[x+i][y+j] = dist[x][y]+1;
                        q.push({x+i,y+j});
                    }
                }
            }
        }
        
        if(dist[m-1][n-1] == INT_MAX)
            return -1;
        return dist[m-1][n-1];
    }
};