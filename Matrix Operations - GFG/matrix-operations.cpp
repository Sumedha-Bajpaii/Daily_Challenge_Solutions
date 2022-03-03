// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> a){
        //code here
        int dir[4][4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int n = a.size(), m = a[0].size();
		int i=0, j=0, r,c;
		int d = 0;
		
		while(i>=0 && i<n && j>=0 && j<m){
		    r = i;
		    c = j;
		    if(a[i][j]==1)
		    {
		        a[i][j] = 0;
		        d = (d+1)%4;
		    }
		    i += dir[d][0];
		    j += dir[d][1];
		}
		return {r,c};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends