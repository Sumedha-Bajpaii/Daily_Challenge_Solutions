class Solution {
public:
    int mod = 1e9+7;
    
    long long f(int i, int pre, int n, vector<vector<long long>>& dp){
        
        if(i==n){
            return 1;
        }
        if(dp[i][pre] != -1)
            return dp[i][pre];
        
        long long tk = 0;
        if( pre % 2 == 1){      // 1 or 3
            tk += f(i+1,pre-1,n,dp) + f(i+1,pre+1,n,dp);
        }
        else if(pre==2){            // 2
            tk += f(i+1,0,n,dp) + f(i+1,1,n,dp) + f(i+1,3,n,dp) + f(i+1,4,n,dp);
        }
        else{                       // 0 or 4
            tk += f(i+1,(pre+1)%5,n,dp);
        }
        return dp[i][pre] = tk%mod;
    }
    
    int countVowelPermutation(int n) {
        
        //string s = "aeiou";
        long long ans=0;
        vector<vector<long long>> dp(n+1,vector<long long>(6,-1));
        
        for(int j=0; j<5; j++){
            ans += f(1,j,n,dp);
        }
        
        return ans%mod;
    }
};