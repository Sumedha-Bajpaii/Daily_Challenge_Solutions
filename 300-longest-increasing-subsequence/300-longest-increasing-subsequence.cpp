class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int last=-1; last<n; last++){
            dp[n][last+1] = 0;
        }
        
        for(int i=n-1; i>=0; i--){
            for(int last = i-1; last>=-1; last--){
                int take = 0;
                if(last==-1 || nums[last]<nums[i])
                    take = 1 + dp[i+1][i+1];
                int notTake = dp[i+1][last+1];
                
                dp[i][last+1] = max(take,notTake);
            }
        }
        
        
        return dp[0][0];
    }
};