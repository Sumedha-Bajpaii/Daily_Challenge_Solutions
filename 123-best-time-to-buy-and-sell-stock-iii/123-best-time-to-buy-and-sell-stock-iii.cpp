class Solution {
public:
    int f(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0)
            return 0;
        
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        
        int profit=0;
        if(buy==1){
            profit = max(-prices[i] + f(i+1,0,k,prices,dp), f(i+1,buy,k,prices,dp));
        }
        else{
            profit = max(prices[i] + f(i+1,1,k-1,prices,dp), f(i+1,buy,k,prices,dp));
        }
        
        return dp[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};