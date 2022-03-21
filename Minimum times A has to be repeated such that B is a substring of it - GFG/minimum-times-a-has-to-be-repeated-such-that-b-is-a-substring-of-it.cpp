// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  //is s2 a substring of s1
    bool isSubStr(string sb,string s)
    {
        int j=0, i=0;
        
        while(i< s.size())
        {
            
            if(s[i]!=sb[j] && j==0){
                i++;
            }
            else if(s[i]!=sb[j] && j>0){
                j=0;
            }
            else{
                i++; j++;
            }
            
            if(j == sb.size())
                return true;
        }
        return false;
    }
    
    int minRepeats(string A, string B) {
        // code here
        string temp = A;
        int cnt = 1;
        
        while(temp.length() < B.length()){
            temp += A;
            cnt++;
        }
        
        if(isSubStr(B,temp))
            return cnt;
            
        temp += A;
        cnt++;
         
        if(isSubStr(B,temp))
            return cnt;
        
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends