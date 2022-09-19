class Solution {
public:
    int f(int prev2, int prev1,vector<int>& arr, unordered_map<int,int>& mp,vector<vector<int>>& dp){
        
        if(dp[prev2][prev1] != -1)
            return dp[prev2][prev1];
            
        int sum = arr[prev2] + arr[prev1];
        
        if(mp.find(sum) != mp.end())
            return dp[prev2][prev1] = 1 + f(prev1,mp[sum],arr,mp,dp);
        
        return dp[prev2][prev1] = 0;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                res = max(res, f(i,j,arr,mp,dp));
            }
        }
        
        if(res+2<3)
            return 0;
        return res+2;
    }
};