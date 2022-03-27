class Solution {
public:
    int f(int ind,int num,int len,string &s,vector<int> &suffix,vector<vector<int>> &dp){
        
        if(ind>=s.size())
            return 0;
        
        if(num==0)
            return suffix[ind];
        
        if(dp[ind][num] != -1)
            return dp[ind][num];
        
        int take = f(ind+len,num-1,len,s,suffix,dp);
        int notTake = f(ind+1,num,len,s,suffix,dp);
        if(s[ind]=='1') notTake++;
        
        return dp[ind][num] = min(take,notTake);
        
    }
    int minimumWhiteTiles(string s, int num, int len) {
        
        int n = s.size();
        vector<int> suffix(n);
        
        if(s[n-1]=='1') suffix[n-1]=1;
        else suffix[n-1]=0;
        
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = suffix[i+1];
            if(s[i]=='1')
                suffix[i]++;
        }
        
        // for(auto i: suffix)
        //     cout<<i<<" ";
        // cout<<endl;
        vector<vector<int>> dp(n,vector<int>(num+1,-1));
        
        return f(0,num,len,s,suffix,dp);
    }
};