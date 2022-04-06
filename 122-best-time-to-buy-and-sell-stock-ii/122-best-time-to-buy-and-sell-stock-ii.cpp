class Solution {
public:
    int f(int i,int buy,vector<int> &a,vector<vector<int>> &dp){
        if(i == a.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        
        int t=0, nt=0;
        
        if(buy==1){
             t = -a[i] + f(i+1,0,a,dp);
             nt = f(i+1,buy,a,dp);
        }                       
        else{
             t = a[i] + f(i+1,1,a,dp);
             nt = f(i+1,buy,a,dp);
        }                                  
  
        return dp[i][buy] = max(t,nt);
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};