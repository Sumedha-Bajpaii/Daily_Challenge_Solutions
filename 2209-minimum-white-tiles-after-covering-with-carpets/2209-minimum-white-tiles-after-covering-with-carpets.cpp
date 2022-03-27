class Solution {
public:
    int f(int ind, int num, int len, string &s, vector<vector<int>> &dp){
        
        if(ind>=s.size())
            return 0;
        
        if(num==0)
        {
            int ones = 0;
            for(int k=ind; k<s.size(); k++)
                if(s[k]=='1')
                    ones++;
            return ones;
        }
        
        if(dp[ind][num] != -1)
            return dp[ind][num];
        
        int take = f(ind+len,num-1,len,s,dp);
        int notTake = f(ind+1,num,len,s,dp);
        if(s[ind]=='1') notTake++;
        
        return dp[ind][num] = min(take,notTake);
        
    }
    int minimumWhiteTiles(string s, int num, int len) {
        
        vector<vector<int>> dp(s.size(),vector<int>(num+1,-1));
        
        return f(0,num,len,s,dp);
    }
};