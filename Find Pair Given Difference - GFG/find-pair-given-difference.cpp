// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends

bool binSearch(int arr[],int l, int h, int key){
    
    while(l<=h){
        int m = l + (h-l)/2;
        if(arr[m]==key)
            return true;
        else if(arr[m]<key)
            l = m+1;
        else
            h = m-1;
    }
    return false;
}

bool findPair(int arr[], int size, int k){
    //code
    sort(arr,arr+size);
    for(int i=0; i<size; i++){
        if(binSearch(arr,i+1,size-1,arr[i]+k))
            return true;;
    }
    return false;
    
}