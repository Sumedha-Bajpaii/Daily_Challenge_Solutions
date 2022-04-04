class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> st;
        int i=0,j=0,len=0,n=s.length();
        while(j<n)
        {
            if(st.find(s[j]) == st.end())
                st.insert(s[j]);
            else
            {
                len = max(len,j-i);
                while(s[i]!=s[j])
                {
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                    i++;
                st.insert(s[j]);
            }
            j++;
        }
        // cout<<st.size();
        if(st.size()>len)
            len = st.size();
        return len;
    }
};