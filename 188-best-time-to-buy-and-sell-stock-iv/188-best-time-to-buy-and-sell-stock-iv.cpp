class Solution {
public:
    int f(int i,int trans,vector<int>& prices,vector<vector<int>> &dp){
        
        if(trans==0 || i==prices.size())
            return 0;
        
        if(dp[i][trans] != -1)
            return dp[i][trans];
        
        int profit=0;
        //trans is even ==> buy
        if(trans%2==0){
            profit = max(-prices[i]+f(i+1,trans-1,prices,dp), f(i+1,trans,prices,dp));
        }
        else{
            profit = max(prices[i]+f(i+1,trans-1,prices,dp), f(i+1,trans,prices,dp));
        }
        
        return dp[i][trans] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        return f(0,2*k,prices,dp);
    }
};