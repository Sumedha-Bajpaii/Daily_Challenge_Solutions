class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        for(auto &c: s){
            if(st.empty() or st.top().first!=c){
                st.push({c,1});
            }
            else{
                st.top().second++;
                if(st.top().second == k){
                        st.pop();
                }
            }
        }
        string res = "";
        while(!st.empty()){
            char x = st.top().first;
            int freq = st.top().second;
            while(freq){
                res += x;
                freq--;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};