class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)), res(n,vector<int>(m));
            // i j d
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int deltaRow[] = {-1,1,0,0};
        int deltaCol[] = {0,0,-1,1};
        
        while(q.size()){
            auto v = q.front(); q.pop();
            int row=v[0], col=v[1], dist=v[2];
            res[row][col] = dist;
            
            for(int i=0; i<4; i++){
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m)
                    continue;
                if(vis[nrow][ncol]==1)
                    continue;
                
                q.push({nrow,ncol,dist+1});
                vis[nrow][ncol] = 1;
            }
        }
        
        return res;
    }
};