class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size(), start, end, maxLen=0, len=0;
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
                
                if(dp[i][j]==true){
                    start=i;  end=j;    len=gap+1;
                }
            }
        }
        
        return s.substr(start,len);
        
    }
};