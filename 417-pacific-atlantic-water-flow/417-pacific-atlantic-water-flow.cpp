class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){

        int n=grid.size();
        int m=grid[0].size();
    
        vis[i][j]=1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        for(int k=0; k<4; k++){
            int nrow = i+delrow[k];
            int ncol = j+delcol[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
               grid[nrow][ncol]>=grid[i][j] && vis[nrow][ncol]==0)
                dfs(nrow,ncol,grid,vis);
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
                        dfs(i,j,grid,pc);
                }
            }
        }
        
        //bottom & right wall
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==n-1 || j==m-1){
                    if(at[i][j]==0)
                        dfs(i,j,grid,at);
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