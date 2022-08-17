class Solution {
public:
    int fun(int cur,string s,vector<string>& dict, vector<int> &dp){
        
        if(cur==s.size())
            return 1;
        if(dp[cur] != -1)
            return dp[cur];
        
        for(auto word: dict){
            int n = word.size();
            if(word == s.substr(cur,n)){
                if(fun(cur+n, s, dict, dp) == 1)
                    return dp[cur] = 1;
            }
        }
        
        return dp[cur] = 0;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
        
        bool ans=false;
        vector<int> dp(s.size()+1, -1);
        
        ans = fun(0,s,dict,dp);
        return ans;
    }
};