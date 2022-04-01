class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);
        
        while(q.size()){
            int cur = q.front();
            q.pop();
            if(arr[cur]==0)
                return true;
            
            int left = cur-arr[cur];
            int right = cur+arr[cur];
            arr[cur] = -1;
            
            if(left>=0 && arr[left]!=-1) q.push(left);
            if(right<n && arr[right]!=-1) q.push(right);
        }
        return false;
    }
};