//why not 3d dp containing l,r,k states
// First, we need to take the position in multipliers at which we calculating in dp state. Again, one of L and R will be sufficient as both L & R are interdependent.
// For e.g. our position in multipliers is k. And our L is x, then R can be calculated as
// R = n - 1 - (k-x)

// Hence, using i and L in dp state is more efficient

class Solution {
public:
    int f(int l,int r,int k,vector<int>& nums,vector<int>& mlt,vector<vector<int>>& dp){
        if(k==mlt.size())
            return 0;
        if(dp[l][k] != INT_MIN)
            return dp[l][k];
        
        int left = nums[l]*mlt[k] + f(l+1,r,k+1,nums,mlt,dp);
        int right = nums[r]*mlt[k] + f(l,r-1,k+1,nums,mlt,dp);
        return dp[l][k] = max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mlt) {
        
        int n = nums.size(), m=mlt.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return f(0,nums.size()-1,0,nums,mlt,dp);
    }
};