class Solution {
public:
    int binSearch(int key, vector<int> &v){
        
        int lo=0, hi=v.size()-1;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(v[mid] == key)
                return mid;
            if(key < v[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }
    
    int minOperations(vector<int>& a, int x) {
        
        int n = a.size();
        vector<int> pre, suf;
        
        pre.push_back(0);
        for(int i=0; i<n; i++){
            pre.push_back(pre.back()+a[i]);
        }
        
        if(pre.back()<x)
            return -1;
        
        suf.push_back(0);
        for(int i=n-1; i>=0; i--){
            suf.push_back(suf.back()+a[i]);
        }
        
        int res=INT_MAX;
        
        for(int i=0; i<n; i++){
            
            if(pre[i] > x)
                break;
            
            int diff = x-pre[i];
            int j = binSearch(diff,suf);
            if(j==-1)
                continue;
            res = min(res, i+j);
        }
        
        if(res==INT_MAX)
            return -1;
        return res;
    }
};