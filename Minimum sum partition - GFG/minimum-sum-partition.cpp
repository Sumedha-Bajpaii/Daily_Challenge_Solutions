// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int f(int n, int s1, int target, int A[], vector<vector<int>> &dp){
        if(n==0)
            return s1;
        if(dp[n][s1] != -1)
            return dp[n][s1];
        
        if(s1+A[n-1]<=target)
            return dp[n][s1] = max( f(n-1,s1+A[n-1],target,A,dp), f(n-1,s1,target,A,dp) );
        else
            return dp[n][s1] = f(n-1,s1,target,A,dp);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++)
	        sum += arr[i];
	    int target = sum/2;
	    
	    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
	    
	    int maxS1 = f(n,0,target,arr,dp);
	    return sum - 2*maxS1;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends