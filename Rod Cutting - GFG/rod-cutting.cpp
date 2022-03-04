// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int index, int len, int price[], vector<vector<int>> &dp){
        if(index==0)        //1 length rod is left
            return price[index]*len;
        
        if(dp[index][len] != -1)
            return dp[index][len];
            
        int take=0, nottake=0;
        
        nottake = 0 + f(index-1, len, price, dp);
        if(index+1<=len)
            take = price[index] + f(index, len-(index+1), price, dp);
        
        return dp[index][len] = max(take, nottake);
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
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