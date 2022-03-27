class Solution {
public:
    int count1(vector<int> &v, int n){
        int l=0, h=n-1;
        
        if(v[h]==1)
            return h+1;
        //find first occur of zero
        while(l<h){
            int mid = (l+h)/2;
            if(v[mid]==0)
                h = mid;
            else
                l = mid+1;
        }
        return h;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<pair<int,int>> pq;
        
        for(auto row=0; row<m; row++)
        {
            int ones = count1(mat[row],n);
            //cout<<ones<<" ";
            pq.push({ones,row});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<int> res;
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};