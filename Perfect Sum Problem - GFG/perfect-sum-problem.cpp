// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int f(int n, int sum, int arr[], vector<vector<int>> &dp){
	    if(n==0)
	        return sum==0;
	       
	    if(dp[n][sum] != -1)
	        return dp[n][sum];
	       
	    int take=0, nottake=0;
	    if(arr[n-1]<=sum)
	        take = f(n-1,sum-arr[n-1],arr,dp);
	    nottake = f(n-1,sum, arr, dp);
	    
	    return dp[n][sum] = (take+nottake)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return f(n, sum, arr, dp);
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