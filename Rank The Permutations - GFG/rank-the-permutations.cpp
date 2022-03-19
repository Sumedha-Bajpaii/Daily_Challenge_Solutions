// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string s) {
        //code here
        int n = s.length();
        long long fact[n+1];
        fact[0] = 1;
        for(int i=1; i<=n; i++)
            fact[i] = fact[i-1] * i;
        
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            for(int j=i+1; j<n; j++){
                if(s[j] < s[i])
                    cnt++;
            }
            ans += cnt * fact[n-1-i];
        }
       
        return ans+1;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends