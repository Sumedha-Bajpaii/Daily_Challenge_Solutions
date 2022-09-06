class Solution {
public:
    int f(int i,int cur, vector<int>& nums, int target, vector<vector<int>>& dp){
        
        if(i==nums.size()){
            if(cur==target)
                return 1;
            else
                return 0;
        }
        if(dp[i][cur+1000] != -1)
            return dp[i][cur+1000];
        
        return dp[i][cur+1000] = f(i+1,cur+nums[i], nums,target,dp) + f(i+1, cur-nums[i], nums,target,dp);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<vector<int>> dp(nums.size(),vector<int>(3000,-1));
        return f(0,0,nums,target,dp);
    }
};