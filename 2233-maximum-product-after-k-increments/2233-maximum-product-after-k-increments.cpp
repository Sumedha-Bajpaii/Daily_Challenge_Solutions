class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        int M = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto x: nums){
            pq.push(x);
        }
        
        while(k){
            int x = pq.top();   pq.pop();
            x++;
            pq.push(x);
            k--;
        }
        
        long long res=1;
        while(!pq.empty()){
            res = (res*pq.top())%M;
            pq.pop();
        }
        
        return res;
    }
};