class Solution {
public:
    bool f(int i,int j,int it,vector<vector<char>>& brd, string s,vector<vector<int>>& vis)
    {
        if(it == s.size()) return true;
        if(i<0 || i>=brd.size() || j<0 || j>=brd[0].size())
            return false;
        bool n1 = false,n2 = false,n3 = false,n4 = false;
        
        if(s[it] == brd[i][j] && vis[i][j] != 1)
        {
            vis[i][j] =1;
            n1 = f(i+1,j,it+1,brd,s,vis);
            n2 = f(i-1,j,it+1,brd,s,vis);
            n3 = f(i,j+1,it+1,brd,s,vis);
            n4 = f(i,j-1,it+1,brd,s,vis);
        }
        else
        {
            return false;
        }
        
        bool ans = n1||n2||n3||n4;
        // cout<<ans << " ";
        vis[i][j] = 0;      //changed
        return ans;
    }
    bool exist(vector<vector<char>>& brd, string word) {
        int n = brd.size(),m = brd[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool ans= false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans = f(i,j,0,brd,word,vis);
               if(ans == true)
                   // break;
                   return ans;      //changed
            }
        }
        return ans;
    }
};