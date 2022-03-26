class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char> st;
        int i, n = s.size();
        
        for(i=0; i<n; i++){
            
            if(st.size()==0 && s[i]=='0')
                continue;
        
            if(st.size()==0 || st.top()<=s[i] || k<=0)
                st.push(s[i]);
        
            else
            {
                st.pop();
                i--;
                k--;
            }   
        }
        
        while(st.size() && k>0){
            st.pop();
            k--;
        }
        
        if(st.size()==0)
            return "0";
        
        string res = "";
        while(st.size()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;

    }
};