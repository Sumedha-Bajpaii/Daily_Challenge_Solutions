class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int i=0, j=0, n=pushed.size();
        
        while(i<n){
            
            if(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            else{
                st.push(pushed[i]);
                i++;
            }
        }
        
        while(j<n && !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
        }
        
        if(st.empty())
            return true;
        else
            return false;
        
    }
};