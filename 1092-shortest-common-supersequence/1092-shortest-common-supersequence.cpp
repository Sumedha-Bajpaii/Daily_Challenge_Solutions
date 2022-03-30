class Solution {
public:
	
    string shortestCommonSupersequence(string s1, string s2) {
        
        int m = s1.size();
	    int n = s2.size();
	    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
	    
        for(int i=0; i<=m; i++) dp[i][0]=0;
        for(int j=0; j<=n; j++) dp[0][j]=0;
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
            
        string lcs = "";
        int i=m,j=n;
        
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                lcs += s1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs<<endl;
        
        int k=0, len=dp[m][n];
        i=0,j=0;
        string res="";
        
        while(k<len){
            if(s1[i] != lcs[k]){
                res += s1[i]; i++;
            }
            else if(s2[j] != lcs[k]){
                res+= s2[j]; j++;
            }
            else{
                res += lcs[k];  k++;
                i++;    j++;
            }   
        }
        
        while(i<m){
            res += s1[i];   i++;
        }
        while(j<n){
            res += s2[j];   j++;
        }
        
	    return res;
    }
};