class Solution {
public:
    // m*n
    void dfs(int i,int j, vector<vector<char>>& grid,int &m, int &n){
        
        grid[i][j] = '2';
        
        if(i-1>=0  &&  grid[i-1][j] == '1')
            dfs(i-1,j,grid,m,n);
        
        if(j+1<n  &&  grid[i][j+1] == '1')
            dfs(i,j+1,grid,m,n);
        
        if(i+1<m  &&  grid[i+1][j] == '1')
            dfs(i+1,j,grid,m,n);
        
        if(j-1>=0  &&  grid[i][j-1] == '1')
            dfs(i,j-1,grid,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int component=0;
        
        //grid[i][j] == '2' means visited
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    component++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        
        return component;
    }
};