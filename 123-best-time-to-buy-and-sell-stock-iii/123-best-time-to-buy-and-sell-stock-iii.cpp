class Solution {
public:
    int f(int i, int buy, int cnt, vector<int>& a,vector<vector<vector<int>>> &dp){
        if(i==a.size())
            return 0;
        if(cnt==4)
            return 0;
        
        if(dp[i][buy][cnt] != -1)
            return dp[i][buy][cnt];
        
        int profit=0;
        if(buy==1){
            profit = max( -a[i]+f(i+1,0,cnt+1,a,dp), f(i+1,1,cnt,a,dp) );
        }
        else{
            profit = max( a[i]+f(i+1,1,cnt+1,a,dp),  f(i+1,0,cnt,a,dp) );
        }
        return dp[i][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(4,-1)));
        return f(0,1,0,a,dp);
    }
};