class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board,int k,string& word){
        
        if(k==word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return false;
        if(board[i][j]=='#' || board[i][j]!=word[k])
            return false;
        
        board[i][j] = '#';      //marking as visited
        
        bool up = dfs(i-1,j,board,k+1,word);
        bool down = dfs(i+1,j,board,k+1,word);
        bool left = dfs(i,j-1,board,k+1,word);
        bool right = dfs(i,j+1,board,k+1,word);
        
        board[i][j] = word[k];      //mark unvisited //backtrack 
        return up || down || left || right;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(i,j,board,0,word) == true)
                    return true;
            }
        }
        
        return false;
    }
};