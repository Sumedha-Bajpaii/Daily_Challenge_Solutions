//Two pointers Solution
class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size(), j=0;
        vector<int> cnt(n);
        
        for(int i=0; i<n; i++,j++){
            s[j] = s[i];
            
            if(j>0 && s[j]==s[j-1])
                cnt[j] = cnt[j-1] + 1;
            else
                cnt[j] = 1;
            
            if(cnt[j]==k)
                j -= k;
        }
        return s.substr(0,j);
    }
};