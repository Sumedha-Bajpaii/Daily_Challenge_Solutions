class Solution {
public:
    long long f(int ind,string &s,vector<long long> &dp){
        
        if(ind==s.size()){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind] != -1)
            return dp[ind];
        
        long long ans=0;
        if(s[ind]=='*'){
            ans = 9*f(ind+1,s,dp); //*_   1,2,3,... 9
        }
        else{
            ans = f(ind+1,s,dp);
        }
        
        if(ind+1<s.size()){
            if(s[ind]=='*'){
                if(s[ind+1]=='*'){
                    ans += 15*f(ind+2,s,dp);
                }
                else if(s[ind+1]-'0'<=6){
                    ans += 2*f(ind+2,s,dp);
                }
                else{
                    ans += f(ind+2,s,dp);
                }
            }
            else if(s[ind]=='1' && s[ind+1]=='*'){
                ans += 9*f(ind+2,s,dp);
            }
            else if(s[ind]=='2' && s[ind+1]=='*'){
                ans += 6*f(ind+2,s,dp);
            }
            else if(s[ind+1]!='*' && stoi(s.substr(ind,2))<=26){
                ans += f(ind+2,s,dp);
            }
        }
        int mod = 1e9+7;
        return dp[ind] = ans%mod;    
        
    }
    
    int numDecodings(string s) {
        
        int mod = 1e9+7;
        vector<long long> dp(s.size(),-1);
        return f(0,s,dp)%mod;
    }
};