// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    string sevenSegments(string S, int N) {
        // code here
        if(S=="8")
        return "8";
        int arr[]={6,2,5,5,4,5,6,3,7,5};
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[S[i]-'0'];
        }
        int ans[N];
        for(int i=0;i<N;i++)
        {
            ans[i]=2;
            sum-=2;
        }
        int i=0;
        while(sum>=4 and i<N){
            ans[i]=6;
            sum+=2;
            sum-=6;
            i++;
        }
        ans[N-1]+=sum;
        string res="";
        for(int i=0;i<N;i++){
            if(ans[i]==6) res+='0';
            
            else if(ans[i]==2) res+='1';
            
            else if(ans[i]==3) res+='7';
            else if(ans[i]==4) res+='4';
            
            else res+='2';
        }
        return res;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends