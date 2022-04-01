class Solution {
public:
    int f(int i,vector<int> &arr){
        if(i<0 || i>=arr.size())
            return 0;
        
        if(arr[i]==-1)  return 0;
        if(arr[i]==0)   return 1;
        
        int temp = arr[i];
        arr[i] = -1;
        int left = f(i-temp,arr);
        int right = f(i+temp,arr);
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        
        return f(start,arr);
    }
};