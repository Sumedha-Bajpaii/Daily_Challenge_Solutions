class Solution {
public:
    int countOrders(int n) {
        long dp[501] = {0};
        dp[1] = 1;
        dp[2] = 6;
        
        for(int i=3; i<=n; i++){
            int odd = 2*i-1;
            int per = (odd*(odd+1))/2;
            dp[i] = (dp[i-1]*per)%1000000007;
        }
        return dp[n];
    }
};