// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int n, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0)
            return 1;
        if(n == 0)
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
            
        if(arr[n-1]<=target)
            return dp[n][target] = f(n-1, target-arr[n-1], arr, dp) || f(n-1, target, arr, dp);
        else
            return dp[n][target] = f(n-1, target, arr,dp);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += arr[i];
            
        if(sum%2 != 0)      //sum is odd
            return 0;
        int target = sum/2;
        
        vector<vector<int>> dp(n+1,vector<int>(target+1, -1));
        
        return f(n,target,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends