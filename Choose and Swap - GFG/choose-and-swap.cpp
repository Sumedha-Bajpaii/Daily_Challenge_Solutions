// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        int found[26] = {0};
        char max_so_far = CHAR_MIN ;
        char smallest   = CHAR_MAX ;
        for(int i = 0  ; i < a.size() ; ++i){
            if(found[a[i] - 'a'] == 0 && a[i] < max_so_far){
                for(int j = i ; j < a.size() ; ++j){
                    if(found[a[j] - 'a'] == 0){
                        smallest = min(smallest , a[j]) ;
                    }
                    found[a[j] - 'a'] = 1 ;
                }
                for(int j = i - 1 ; j >= 0 ; --j){
                    if(a[j] > smallest){
                        max_so_far = a[j] ;
                    }
                }
                break;
            }
            max_so_far = max(max_so_far , a[i]);
            found[a[i] - 'a'] = 1 ;
        }
        if(max_so_far != CHAR_MIN && smallest != CHAR_MAX){
            for(int i = 0 ; i < a.size() ; ++i){
                if(a[i] == max_so_far){
                    a[i] = smallest ;
                }
                else if(a[i] == smallest){
                    a[i] = max_so_far ;
                }
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends