class Solution {
public:
    bool buddyStrings(string s, string t) {
        
        if(s.size()!=t.size())
            return false;
        
        if(s==t){
            sort(s.begin(),s.end());
            for(int i=1; i<s.size(); i++){
                if(s[i]==s[i-1])
                    return true;
            }
            return false;
        }
        
        vector<int> v;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i])
                v.push_back(i);
        }
        if(v.size()==2)
        {
            swap(s[v[0]],s[v[1]]);
            if(s==t)
                return true;
        }
        return false;
    }
};