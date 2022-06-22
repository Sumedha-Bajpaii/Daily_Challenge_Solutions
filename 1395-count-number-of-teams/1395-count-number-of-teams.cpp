class Solution {
public:
    int numTeams(vector<int>& A) {
        
        int inc=0, dec=0, n=A.size();
        
        vector<int> big(n,0), sml(n,0);
        
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(A[j]<A[k]){
                    big[j]++;
                }
            
                if(A[j]>A[k]){
                    sml[j]++;
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(A[i]<A[j]){
                    inc += big[j];
                }
                
                if(A[i]>A[j]){
                    dec += sml[j];
                }
            }
        }
        
        
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(A[j]<A[i]){
        //             for(int k=j+1; k<n; k++){
        //                 if(A[k]<A[j]){
        //                     dec++;
        //                 }
        //             }
        //         }
        //     }
        // }
        
        return inc + dec;
    }
};