class Solution {
public:
    int f(int i,int p,vector<int> &a,vector<vector<int>> &dp){
        if(i == a.size()-1){
            if(p==1)
                return a[i];
            return 0;
        }
        if(dp[i][p] != -1)
            return dp[i][p];
        
        int t=0, nt = f(i+1,p,a,dp);
        
        if(p==0)                                  //buy
            t = -a[i] + f(i+1,p^1,a,dp);
        else                                      //sell
            t = a[i] + f(i+1,p^1,a,dp);
        
        return dp[i][p] = max(t,nt);
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};