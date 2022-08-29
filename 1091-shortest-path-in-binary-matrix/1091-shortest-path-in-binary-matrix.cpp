class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0] != 0)
            return -1;
        
        //vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        // dist[0][0] = 1;
        
        int steps = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
        
            steps++;
            int sz = q.size();
            
            for(int k=0; k<sz; k++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x==m-1 && y==n-1)
                    return steps;
                
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        // if(i==0 && j==0)
                        //     continue;
                        if(x+i<0 or x+i>=m or y+j<0 or y+j>=n)
                            continue;
                        if(grid[x+i][y+j]==1)
                            continue;
                        
                        q.push({x+i,y+j});
                        grid[x+i][y+j] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};