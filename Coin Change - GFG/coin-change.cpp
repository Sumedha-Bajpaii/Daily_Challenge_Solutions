// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int f(int idx, int amt, int A[], vector<vector<long long int>> &dp){
        
        if(idx==-1)
            if(amt == 0)
                return 1;
            else
                return 0;
        
        if(dp[idx][amt] != -1)
            return dp[idx][amt];
            
        long long int take=0, nottake=0;
        if(A[idx] <= amt)
            take = f(idx, amt-A[idx], A, dp);
        nottake = f(idx-1, amt, A, dp);
        
        return dp[idx][amt] = (take + nottake);
    }
    
    long long int count(int S[], int m, int n){ 
        // code here.
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        return f(m-1,n,S,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends