// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const unsigned int M = 1000000007;
class Solution{
	public:
	int f(int n, int sum, int arr[], vector<vector<int>> &dp){
	   // if(sum==0)
	   //     return 1;
	    if(n==0)
	        return sum==0;
	    
	    if(dp[n][sum] != -1)
	        return dp[n][sum];
	    
	    if(arr[n-1]<=sum)
	        return dp[n][sum] = ( f(n-1,sum-arr[n-1],arr,dp) + f(n-1,sum,arr,dp) )%M;
	    return dp[n][sum] = f(n-1,sum,arr,dp)%M;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n,sum,arr,dp);
	}
	  
};
// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends