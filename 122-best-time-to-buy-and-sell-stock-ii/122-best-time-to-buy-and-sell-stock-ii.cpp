class Solution {
public:
    
    int maxProfit(vector<int>& a) {
        int n = a.size();
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        //dp[n][0] = dp[n][1] = 0;
        int f=0, s=0;
        
        for(int i = n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int t=0, nt=0, profit=0;
                if(buy==1){
                     t = -a[i] + f;
                     nt = s;
                     profit = max(t,nt);
                     s = profit;
                }                       
                else{
                     t = a[i] + s;
                     nt = f;
                     profit = max(t,nt);
                     f = profit;
                }                                  
            }
        }
        
        // return max(dp[0][0],dp[0][1]);
        return s;
    }
};