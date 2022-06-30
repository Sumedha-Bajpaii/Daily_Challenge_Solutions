// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int> res;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        for(int i=0; i<k; i++){
            minHeap.push({arr[i][0],i,0});
        }
        // v = [data, row, col]
        
        
        while(minHeap.size()){
            
            auto v = minHeap.top();
            minHeap.pop();
            int data=v[0], row=v[1], col=v[2];
            //cout<<data<<" ";
            res.push_back(data);
            
            if(col+1 < arr[row].size())
                minHeap.push({arr[row][col+1], row, col+1});
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends