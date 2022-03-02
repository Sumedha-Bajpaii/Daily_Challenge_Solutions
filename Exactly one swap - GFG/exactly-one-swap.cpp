// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string s)
    {
        // code here
        map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        int n = s.size();
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            int cnt = (n-(i+1)) - (mp[s[i]] - 1);
            mp[s[i]]--;
            ans += cnt;
        }
        if(set<char>(s.begin(),s.end()).size()==s.size())
            return ans;
        else
            return ans+1;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends