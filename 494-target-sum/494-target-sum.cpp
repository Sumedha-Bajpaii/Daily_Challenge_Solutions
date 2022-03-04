class Solution {
public:
    int f(int n, int sum, vector<int> &a, vector<vector<int>> &dp){
        if(n==0)
            return sum==0;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(a[n-1] <= sum)
            return dp[n][sum] = f(n-1,sum-a[n-1],a,dp) + f(n-1,sum,a,dp);
        return dp[n][sum] = f(n-1, sum,a,dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int diff) {
        
        int n = nums.size(), total = 0;
        for(auto i: nums)
            total += i;
        //s1 - s2 = diff
        //s1 - (total - s1) = diff
        //2*s1 = diff + total 
        //s1 = (diff + total)/2
        if((diff + total)%2 != 0)
            return 0;
        
        int sum = (diff + total)/2;
        if(sum<0 || sum>total)  return 0;
        //find how many ways we can have a subset with given sum
        //count subset sum
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n,sum,nums,dp);
    }
};