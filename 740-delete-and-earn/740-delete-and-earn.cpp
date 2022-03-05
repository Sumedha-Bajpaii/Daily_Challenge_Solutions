class Solution {
public:
    int f(int idx, vector<int> &fr, vector<int> &dp){
        if(idx<0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = idx*fr[idx] + f(idx-2, fr, dp);
        int nottake = f(idx-1, fr, dp);
        
        return dp[idx] = max(take,nottake);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int mx = -1;
        for(auto i: nums)
            if(i>mx)
                mx = i;
        
        vector<int> fr(mx+1,0);
        for(auto i: nums)
            fr[i]++;
        
        vector<int> dp(mx+1,-1);
        
        return f(mx,fr,dp);
        
    }
};