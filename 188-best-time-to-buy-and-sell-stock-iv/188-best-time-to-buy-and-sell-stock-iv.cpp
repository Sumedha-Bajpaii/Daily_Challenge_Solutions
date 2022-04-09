class Solution {
public:
    
    int maxProfit(int cnt, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(cnt+1,0)));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int k=1; k<=cnt; k++){
                    int profit=0;
                    if(buy==1){
                        profit = max(-prices[i] + dp[i+1][0][k], dp[i+1][buy][k]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][k-1], dp[i+1][buy][k]);
                    }
                    dp[i][buy][k] = profit;
                }
            }
        }
        
        return dp[0][1][cnt];
    }
};