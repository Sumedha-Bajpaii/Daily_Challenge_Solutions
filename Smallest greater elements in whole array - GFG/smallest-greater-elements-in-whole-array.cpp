// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int v[], int n)
{
set<int> st;
    for(int i=0;i<n;i++)
    st.insert(v[i]);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        auto it=st.find(v[i]);
        if(it!=st.end() && (++it)!=st.end())
        ans.push_back(*(it));
        else
        ans.push_back(-10000000);
    }
    for(int i=0;i<n;i++)
    v[i]=ans[i];
    return v;
    
    
}