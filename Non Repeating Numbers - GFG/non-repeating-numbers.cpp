//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> res;
        // int n = sizeof(nums) / sizeof(nums[0]);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // cout<<sizeof(nums) <<" "<< sizeof(nums[0])<< " "<<n<<endl;
        for(int i=0; i<n-1 ; i++)
        {
            // cout<<i<<" : "<<nums[i]<<" "<<nums[i+1]<<endl;
            if(nums[i]==nums[i+1])
                i=i+1;
            else
                res.push_back(nums[i]);
        }
        
        if(n>=2 && nums[n-1]!=nums[n-2])
            res.push_back(nums[n-1]);
        // else
        //     res.push_back(nums[n-1]);
        sort(res.begin(), res.end());
        return res;
    }
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    // 3 3 5 5 7 7 8 8 9 9 16 19 19 20 20 25 26 26 27 27
};

 

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends