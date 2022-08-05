class Solution {
public:
    int f(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(i==nums.size()){
            if(target==0)
                return 1;
            else
                return 0;
        }
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int t=0, nt=0;
        if(nums[i] <= target){
            t = f(0,target-nums[i],nums,dp);
        }
        nt = f(i+1,target,nums,dp);
        
        return dp[i][target] = t+nt;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return f(0,target,nums,dp);
    }
};
