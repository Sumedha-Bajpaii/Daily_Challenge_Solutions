class Solution {
public:
    int f(int i,int last,vector<int>& nums,int **dp){
        
        if(i>=nums.size())
            return 0;
        
        if(dp[i][last+1] != -1)
            return dp[i][last+1];
        
        int take = 0;
        if(last==-1 || nums[last]<nums[i])
            take = 1 + f(i+1,i,nums,dp);
        int notTake = f(i+1,last,nums,dp);
        
        return dp[i][last+1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        //vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int **dp = new int *[n+1];
        
         for(int i = 0; i <= n; i++) {
		    dp[i] = new int[n+1];
		    for(int j = 0; j <= n; j++) {
		    	dp[i][j] = -1;
		    }
	    }
        
        return f(0,-1,nums,dp);
    }
};