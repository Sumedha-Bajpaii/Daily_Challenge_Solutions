// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v;
        int maxTime = INT_MIN;
        for(int i=0; i<n; i++)
        {
            v.push_back({arr[i].profit,arr[i].dead});
            maxTime = max(maxTime,arr[i].dead);
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<int> timeLine(maxTime+1,0);
        int profit=0, job=0;
        for(auto p: v){
            int last=p.second;
            for(;last>0;last--){
                if(timeLine[last]==0)
                {
                    timeLine[last] = p.first;
                    profit += p.first;
                    job++;
                    break;
                }
            }
        }

        return {job,profit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends