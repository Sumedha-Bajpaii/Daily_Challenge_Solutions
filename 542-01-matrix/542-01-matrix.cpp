class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        //m*n matrix
        int m=mat.size(), n=mat[0].size(), i,j;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        
        //x y d
        queue<vector<int>> q;
        
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                    mat[i][j] = -1;
                    break;
                }
            }
        }
        
        while(!q.empty()){
            auto v = q.front(); q.pop();
            int x=v[0], y=v[1], d=dist[x][y];
            
            for(auto dir: directions){
                i=x+dir[0]; j=y+dir[1];
                if(i<0 ||j<0 ||i>=m ||j>=n)
                    continue;
                
                if(mat[i][j]==1 && dist[i][j] > d+1){
                    dist[i][j] = d+1;
                    q.push({i,j});
                }
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                    mat[i][j] = -1;
                }
            }
        }
        
        return dist;
    }
};