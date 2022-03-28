// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    void f(int s, int k, vector<int> &v)
    {
        if(v.size() == 1)
            return;
        
            int t = (s+k)%v.size();
            v.erase(v.begin()+t);
            f(t,k,v);
    }
    
    int safePos(int n, int k) {
        // code here
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
            
        f(0,k-1,v);
        return v[0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends