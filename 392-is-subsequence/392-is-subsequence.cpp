class Solution {
public:
    int f(string &s, string &t, int m, int n){
        if(m==0 or n==0)
            return 0;
        
        if(s[m-1] == t[n-1])
            return 1 + f(s,t,m-1,n-1);
        
        return f(s,t,m,n-1);
        
    }
    bool isSubsequence(string s, string t) {
        int m=s.size(), n=t.size();
        return f(s,t,m,n)==m;
    }
};