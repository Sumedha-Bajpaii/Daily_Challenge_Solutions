// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        // Code Here
        while(n){
            int a = x>>p1 & 1;
            int b = x>>p2 & 1;
            if(a != b){
                x = x ^ 1<<p1;
                x = x ^ 1<<p2;
            }
            n--;
            p1++;
            p2++;
        }
        return x;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends