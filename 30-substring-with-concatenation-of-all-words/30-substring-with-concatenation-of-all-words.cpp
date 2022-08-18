class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        int len = words[0].size();
        int total = words.size()*len;
        
        unordered_map<string,int> fr, mp;
        unordered_set<string> st;
        
        for(auto word: words){
            fr[word]++;
        }
        
        
        for(int i=0; i<s.size()-total+1; i++){
            
            // if(st.find(s.substr(i+total)) != st.end()){
            //     res.push_back(i);
            //     continue;
            // }
            
            int j=i;
            mp = fr;
            while(j < i+total){
                string ss = s.substr(j,len);
                
                if(mp.find(ss) != mp.end()   &&   mp[ss]>0){
                    mp[ss]--;
                    j += len;
                }
                else
                    break;
            }
            
            if(j == i+total){
                res.push_back(i);
                st.insert(s.substr(i,total));
            }
                
        }
        
        return res;
    }
};