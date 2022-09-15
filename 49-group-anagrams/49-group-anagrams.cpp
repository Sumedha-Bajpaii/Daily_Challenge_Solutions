class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> mp;
        
        for(auto s: strs){
            vector<int> temp(26,0);
            for(auto c: s){
                temp[c-'a']++;
            }
            mp[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto p: mp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};