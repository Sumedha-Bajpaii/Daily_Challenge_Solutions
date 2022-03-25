class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> req;
        
        for(int i=0; i<t.size(); i++){
            req[t[i]]++;
        }
        
        int i=0,j=0, n=s.size();
        unordered_map<char,int> cur;
        unordered_set<char> done;
            
        int mn = INT_MAX, start=-1;
        
        while(j<n)
        {
            if(req.find(s[j]) != req.end())
            {
                cur[s[j]]++;
                if(cur[s[j]] >= req[s[j]])
                    done.insert(s[j]);   
            }
            while(done.size()==req.size())
            {
                if(j-i+1 < mn)
                {
                    mn = j-i+1;
                    start = i;
                }          
                if(cur.find(s[i])!=cur.end())
                {
                    cur[s[i]]--;
                    if(cur[s[i]] < req[s[i]])
                        done.erase(s[i]);
                }
                i++;
            }         
            j++;
        }
        
        if(mn==INT_MAX)
            return "";
        return s.substr(start,mn);
    }
};