class Solution {
public:
    int f(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(i>=prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit=0;
        if(buy==1){
            profit = max(-prices[i]+f(i+1,0,prices,dp), f(i+1,buy,prices,dp));
        }
        else{
            profit = max(prices[i]+f(i+2,1,prices,dp), f(i+1,buy,prices,dp));
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};