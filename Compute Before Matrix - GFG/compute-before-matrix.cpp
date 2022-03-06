// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> A){
        // Code here
        vector<vector<int>> B(N,vector<int>(M));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                B[i][j] = A[i][j];
                if(i-1>=0)  B[i][j] -= A[i-1][j];
                if(j-1>=0)  B[i][j] -= A[i][j-1];
                if(i-1>=0 && j-1>=0)    B[i][j] += A[i-1][j-1];
            }
        }
        
        return B;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends