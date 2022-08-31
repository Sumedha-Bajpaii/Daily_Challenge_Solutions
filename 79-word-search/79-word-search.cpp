class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    bool f(int i,int j, int k, string& word, vector<vector<char>> &board){
        
        if(k==word.size())
            return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#')
            return false;
        
        if(board[i][j] != word[k])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        for(auto &d: dir){
            if(f(i+d[0], j+d[1], k+1, word, board) == true)
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    bool res = f(i,j,0,word,board);
                    if(res == true)
                        return res;
                }
            }
        }
        
        return false;
    }
};