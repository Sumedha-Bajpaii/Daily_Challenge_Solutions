class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& A) {
        
        vector<int> st;
        int i=0, n=A.size();
        
        for(int i=0; i<n; i++){
            st.push_back(A[i]);
            
            while(st.size()>=2){
                long x = st[st.size()-1];
                long y = st[st.size()-2];
                long g = __gcd(x,y);
                
                if(g>1){
                    st.pop_back();
                    st.pop_back();
                    //LCM(x,y) * HCF(x,y) = x*y
                    st.push_back( (x*y)/g );
                }
                else
                    break;        
            }
            
        }
        
        return st;
    }
};