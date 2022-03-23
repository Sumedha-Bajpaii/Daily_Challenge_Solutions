class Solution {
public:
    string smallestSubsequence(string s) {
        
        unordered_map<char,int> lastInd;
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            lastInd[s[i]] = i;
        }
        
        stack<char> st;
        vector<bool> picked(26,false);
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(picked[ch-'a'] == false)
            {
                if(st.size()==0 || st.top()<ch)
                {
                    st.push(ch);
                    picked[ch-'a'] = true;
                }
                else if(st.top()>ch && lastInd[st.top()]<i)
                {
                    st.push(ch);
                    picked[ch-'a'] = true;
                }
                else
                {
                    picked[st.top()-'a'] = false;
                    st.pop();
                    i--;
                }
            }
        }
        string res = "";
        
        while(!st.empty()){
            //cout<<st.top()<<" ";
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};