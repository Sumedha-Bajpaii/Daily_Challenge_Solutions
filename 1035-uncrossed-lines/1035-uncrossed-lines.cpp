class Solution {
public:
    int lcs(int i, int j, vector<int>& a1, vector<int>& a2, vector<vector<int>> &dp)
    {
        if(i==a1.size() || j==a2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(a1[i]==a2[j])
            return dp[i][j] = 1+lcs(i+1,j+1,a1,a2,dp);
        else
            return dp[i][j] = max(lcs(i+1,j,a1,a2,dp), lcs(i,j+1,a1,a2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return lcs(0,0,nums1,nums2,dp);
    }
};