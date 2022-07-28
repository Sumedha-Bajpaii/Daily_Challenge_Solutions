class Solution {
public:
    int f(int ind,string &s,vector<int> &dp){
        
        if(ind==s.size()){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind] != -1)
            return dp[ind];
        
        if(ind+1<s.size() && stoi(s.substr(ind,2))<=26){
            return dp[ind] = f(ind+1,s,dp) + f(ind+2,s,dp);
        }
        return dp[ind] = f(ind+1,s,dp);    
        
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size(),-1);
        return f(0,s,dp);
    }
};