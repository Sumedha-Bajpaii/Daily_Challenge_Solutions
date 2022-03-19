class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        unordered_map<char,int> mp;
        mp['('] = 1;    mp[')'] = 10;
        mp['{'] = 2;    mp['}'] = 20;
        mp['['] = 3;    mp[']'] = 30;
        
        for(auto c: s){
            if(mp[c] <= 3)
                st.push(c);
            else{
                if(st.empty())
                    return false;
                if(mp[st.top()]*10 == mp[c])
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};