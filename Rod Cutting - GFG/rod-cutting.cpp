// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int n, int len, int price[], vector<vector<int>> &dp){
        if(n==0)
            return 0;
        
        if(dp[n][len] != -1)
            return dp[n][len];
            
        int take=0, nottake=0;
        if(n<=len)
            take = price[n-1] + f(n, len-n, price, dp);
        
        nottake = f(n-1, len, price, dp);
        return dp[n][len] = max(take, nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(n,n,price,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends