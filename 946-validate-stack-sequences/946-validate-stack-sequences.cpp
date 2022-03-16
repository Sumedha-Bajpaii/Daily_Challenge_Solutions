class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        vector<int> st;
        int i=0, j=0, n=pushed.size();
        
        while(i<n){
            
            if(st.size()>0 && st.back() == popped[j]){
                st.pop_back();
                j++;
            }
            else{
                st.push_back(pushed[i]);
                i++;
            }
        }
        
        while(j<n && st.size()>0 && st.back()==popped[j]){
                st.pop_back();
                j++;
        }
        
        if(st.size()==0)
            return true;
        else
            return false;
        
    }
};