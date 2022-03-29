class Solution {
public:
    int f(int row,int k,vector<vector<int>>& piles, vector<vector<int>> &dp){
        if(k==0)
            return 0;
        
        if(row==0){
            int sum=0, n=piles[row].size();
            if(k>n)
                return INT_MIN;
            for(int j=0; j<k; j++)
                sum += piles[row][j];
            return sum;
        }
        if(dp[row][k] != -1)
            return dp[row][k];
        
        int ans = INT_MIN;
        //not take any coin from current row
        ans = max(ans, f(row-1,k,piles,dp));
        
        //take 1 to k coins from row'Th pile
        int sum=0, n=piles[row].size();
        for(int j=0; j<n && j<k; j++){
            sum += piles[row][j];
            int temp = f(row-1,k-j-1,piles,dp);
            ans = max(ans,sum+temp);
        }
        return dp[row][k] = ans;
    }
        
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int row = piles.size();
        vector<vector<int>> dp(row+1,vector<int>(k+1,-1));
        return f(row-1,k,piles,dp);
    }
};