class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        int m = A.size(), n=B.size();
        vector<int> temp(m+n,0);
        
        int i=0, j=0, k=0;
        
        while(i<m && j<n){
            if(A[i]<=B[j]){
                temp[k] = A[i]; i++;
            }
            else{
                temp[k] = B[j]; j++;
            }
            k++;
        }
        while(i<m){
            temp[k]=A[i]; i++; k++;
        }
        while(j<n){
            temp[k]=B[j]; j++; k++;
        }
        
        // for(auto x: temp){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        int p = m+n;
        if(p%2==0){
            return (temp[p/2] + temp[p/2 - 1])/2.0;
        }
        
        return temp[p/2];
    }
};