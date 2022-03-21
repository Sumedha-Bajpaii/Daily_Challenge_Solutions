class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                if(st.empty())
                    s[i] = '#';
                else
                    st.pop();
            }   
        }
        
        
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        string res="";
        //cout<<s<<endl;
        for(auto c: s)
            if(c != '#')
                res += c;
        
        return res;
    }
};