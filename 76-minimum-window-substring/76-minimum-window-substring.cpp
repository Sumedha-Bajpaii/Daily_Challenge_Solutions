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
            
        int mn = INT_MAX;
        pair<int,int> ans = {-1,-1};
        
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
                    ans = {i,j};
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
        
        //cout<<mn<<endl;
        //cout<<s.substr(ans.first,mn)<<endl;
        
        if(mn==INT_MAX)
            return "";
        return s.substr(ans.first,mn);
    }
};