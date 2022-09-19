class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){

        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        while(q.size()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   grid[nrow][ncol]>=grid[row][col] && vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> pc(n,vector<int>(m,0));
        vector<vector<int>> at(n,vector<int>(m,0));
        
        //top & left wall
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    if(pc[i][j]==0)
                        // dfs(i,j,grid,pc);
                        bfs(i,j,grid,pc);
                }
            }
        }
        
        //bottom & right wall
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==n-1 || j==m-1){
                    if(at[i][j]==0)
                        // dfs(i,j,grid,at);
                        bfs(i,j,grid,at);
                }
            }
        }
        
        vector<vector<int>> res;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pc[i][j] && at[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
};