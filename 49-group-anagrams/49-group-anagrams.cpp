class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        
        for(auto s: strs){
            // string temp = s;
            // sort(temp.begin(),temp.end());
            //sort s using counting sort as s has only 26 different characters
            string temp = mySort(s);
            mp[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto p: mp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
    
    string mySort(string s){
        
        int freq[26] = {0};
        for(int i=0; i<s.size(); i++)
            freq[s[i]-'a']++;
        
        string t = "";
        for(int i=0; i<26; i++){
            t += string(freq[i],i+'a');
        }
        
        return t;
    }
};