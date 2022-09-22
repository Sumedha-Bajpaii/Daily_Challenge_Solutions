class Solution {
public:
    int f(int i,int pre,vector<vector<int>>& v,vector<vector<int>>& dp){
        
        if(i>=v.size())
            return 0;
        if(dp[i][pre+1] != -1)
            return dp[i][pre+1];
        
        int tk=-1e9,nt=-1e9;
        if(pre==-1 or v[pre][1]<v[i][0])
            tk = 1 + f(i+1,i,v,dp);
        nt = f(i+1,pre,v,dp);
        
        return dp[i][pre+1] = max(tk,nt);
    }
    int findLongestChain(vector<vector<int>>& v) {
        
        int n = v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,v,dp);
    }
};