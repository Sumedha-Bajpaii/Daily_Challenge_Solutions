//Think when constraint K is removed and u can chose any number of engineers
class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        
        vector<pair<int,int>> engineers;
        for(int i=0; i<n; i++){
            engineers.push_back({eff[i],speed[i]});
        }
        
        //sort then reverse || sort in reverse order
        sort(engineers.rbegin(), engineers.rend());
        
        priority_queue< int, vector<int>, greater<int>> minHeap;
        int e,s;
        long ans=0, totalSpeed=0;
        
        for(int i=0; i<n; i++){
            e = engineers[i].first;   s = engineers[i].second;
            totalSpeed += s;
            
            if(minHeap.size() == k){
                totalSpeed -= minHeap.top();
                minHeap.pop();
            }
            minHeap.push(s);
            ans = max(ans, e*totalSpeed);
        }
        
        return ans%MOD;
    }
};