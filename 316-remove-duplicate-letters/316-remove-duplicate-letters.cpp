class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> lastInd(26);
        for(int i=0; i<s.size(); i++){
            lastInd[s[i]-'a'] = i;
        }
        
        vector<bool> picked(26,false);
        stack<char> st;
        
        int i=0, n = s.size();
       
        while(i < n)
        {    
            char ch = s[i];
            if(picked[ch-'a'] == false)
            {
                while(st.size()>0 && st.top()>ch && lastInd[st.top()-'a']>i)
                {
                    picked[st.top()-'a'] = false;
                    st.pop();
                } 
                st.push(ch);
                picked[ch-'a'] = true;
            }
            i++;
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
    
        reverse(res.begin(),res.end());
        return res;
    }
};