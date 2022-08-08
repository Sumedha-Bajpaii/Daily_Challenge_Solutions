class Solution {
public:
    int f(int cur, int pre, vector<int>& nums, vector<vector<int>>& dp){
        
        if(cur==nums.size())
            return 0;
        if(dp[cur][pre+1] != -1)
            return dp[cur][pre+1];
        
        int tk=0,nt=0;
        //take
        if(pre==-1 || nums[pre]<nums[cur]){
            tk = 1 + f(cur+1,cur,nums,dp);
        }
        //not take
        nt = f(cur+1,pre,nums,dp);
        
        return dp[cur][pre+1] = max(tk,nt);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};