class Solution {
public:
//     long long f(int i,int j,string &s,string &x,vector<vector<long long>> &dp){
        
//         if(j==0)    return 1;
//         if(i==0)    return 0;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         long long t=0, nt=0;
//         if(s[i-1]==x[j-1])
//             t = f(i-1,j-1,s,x,dp);
//         nt = f(i-1,j,s,x,dp);
        
//         return dp[i][j] = t+nt;
//     }
    
    long long count(string &s, string x){
        long long m = s.size();
        long long n = x.size();
        
        long long dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(long long i=0; i<=m; i++)   dp[i][0]=1;
        
        for(long long i=1; i<=m; i++){
            for(long long j=1; j<=n; j++){
                long long t=0, nt=0;
                if(s[i-1]==x[j-1])
                    t = dp[i-1][j-1];
                nt = dp[i-1][j];
                
                dp[i][j] = t+nt;
            }
        }
        return dp[m][n];
    }
    
    long long numberOfWays(string s) {
        
        return count(s,"010") + count(s,"101");
    }
};