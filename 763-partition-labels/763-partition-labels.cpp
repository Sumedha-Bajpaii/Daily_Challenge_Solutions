class Solution {
public:
    vector<int> partitionLabels(string s) {
       
        unordered_map<char,int> mp;
        
        int n = s.length();
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        
        vector<int> ans;
        
        int prev=-1, maxi=0;
        
        for(int cur=0; cur<n; cur++){
            maxi = max(maxi, mp[s[cur]]);
            if(cur == maxi){
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        
        return ans;
    }
};