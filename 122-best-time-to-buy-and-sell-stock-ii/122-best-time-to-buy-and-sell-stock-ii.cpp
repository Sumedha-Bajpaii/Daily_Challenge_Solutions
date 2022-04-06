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
    
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int i = n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int t=0, nt=0, profit=0;
                if(buy==1){
                     t = -a[i] + dp[i+1][0];
                     nt = dp[i+1][1];
                     profit = max(t,nt);
                }                       
                else{
                     t = a[i] + dp[i+1][1];
                     nt = dp[i+1][0];
                     profit = max(t,nt);
                }                                  
                dp[i][buy] = profit;
            }
        }
        
        // return max(dp[0][0],dp[0][1]);
        return dp[0][1];
    }
};