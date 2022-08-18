class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        // int mod = 1e9+7;
        int mod = 1000000007;
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }
        
        vector<long long> dp(arr.size(),1);
        
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<i; j++){
                
                if(arr[i]%arr[j]==0  &&  mp.find(arr[i]/arr[j]) != mp.end()){
                    int t = mp[arr[i]/arr[j]];
                    dp[i] += dp[j] * dp[t];
                }
            }
        }
        
        
        long long ans = 0;
        for(auto x: dp){
            ans += x;
            // ans = ans%mod;
        }
        
        return ans%mod;
    }
};