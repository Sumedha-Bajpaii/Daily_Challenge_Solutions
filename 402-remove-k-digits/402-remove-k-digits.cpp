class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        
        for(int i=0; i<num.size(); i++){
            if(!st.empty() && st.top()>num[i] && k){
                st.pop();
                k--;    i--;
            }
            else{
                st.push(num[i]);
            }
        }
        while(k){
            st.pop();
            k--;
        }
        
        string res = "";
        while(st.size()){
            res += st.top();
            st.pop();
        }
        while(res.back()=='0')
            res.pop_back();
        reverse(res.begin(), res.end());
        
        if(res.size()==0)
            return "0";
        return res;
    }
};