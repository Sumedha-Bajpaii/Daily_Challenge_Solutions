// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    long long countPairs(int N, int X, vector<int> arr){
        // code here
        string x = to_string(X);
        
        unordered_map<string,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[to_string(arr[i])]++;
        }
        
        long long cnt=0;
        
        for(int i=0; i<x.size(); i++)
        {
            string pre = x.substr(0,i+1);
            string suf = x.substr(i+1);
            
            if(mp.find(pre)!=mp.end() && mp.find(suf)!=mp.end())
            {
                if(pre==suf){
                    int n = mp[pre];
                    cnt += n*(n-1);
                }
                else
                    cnt += mp[pre]*mp[suf];
            }
        }
        
        return cnt;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends