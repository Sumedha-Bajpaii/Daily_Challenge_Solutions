// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int ind, int target, vector<int> v, vector<vector<int>> &dp){
        if(ind==-1)
            if(target==0)
                return true;
            else
                return false;
        if(dp[ind][target] != -1)
            return dp[ind][target];
            
        bool take=false,nottake=false;
        
        if(v[ind]<=target)
            take = f(ind-1,target-v[ind],v,dp);
        nottake = f(ind-1,target,v,dp);
        
        return dp[ind][target] = (take or nottake);
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        vector<int> v;
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
            v.push_back(arr[i]);
        }
        
        if(sum%2!=0)
            return false;
        
        vector<vector<int>> dp(N+1,vector<int>(sum/2+1,-1));
        bool res = f(N-1,sum/2,v,dp);
        if(res)
            return 1;
        else
            return 0;
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