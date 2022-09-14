class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size(), count=0;
        bool dp[n][n];
        
        for(int gap=0; gap<n; gap++){
            int i,j;
            for(i=0, j=gap; j<n ; i++,j++){
                if(gap==0)
                    dp[i][j] = true;
                else if(gap==1){
                    if(s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                
                if(dp[i][j]==true)
                    count++;
            }
        }
        
        return count;
    }
};