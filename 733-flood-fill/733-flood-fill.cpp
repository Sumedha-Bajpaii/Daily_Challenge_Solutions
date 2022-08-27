class Solution {
public:
    void dfs(int i,int j, int &old, int &neww, vector<vector<int>>& img){
        
        //cout<<i<<" "<<j<<endl;
        img[i][j] = neww;
        int m=img.size(), n=img[0].size();
        
        if(i-1>=0 && img[i-1][j]==old)
            dfs(i-1,j,old,neww,img);
        
        if(j+1<n && img[i][j+1]==old)
            dfs(i,j+1,old,neww,img);
        
        if(i+1<m && img[i+1][j]==old)
            dfs(i+1,j,old,neww,img);
        
        if(j-1>=0 && img[i][j-1]==old)
            dfs(i,j-1,old,neww,img);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color)
            return image;
        
        int tmp = image[sr][sc];
        // dfs(sr,sc,image[sr][sc], color,image);
        dfs(sr,sc,tmp, color,image);
        return image;
    }
};