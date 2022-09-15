class Solution {
public:
    int trap(vector<int>& h) {
        
        //find farthest highest building on both left and right
        int n = h.size();
        vector<int> left(n,0), right(n,0);
        
        int hsr=0;              //highest so far  //left to right
        for(int i=0; i<n; i++){
            hsr = max(hsr,h[i]);
            left[i] = hsr;
        }
        
        hsr = 0;                //right to left
        for(int i=n-1; i>=0; i--){
            hsr = max(hsr,h[i]);
            right[i] = hsr;
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            //water above i'th building
            int t = min(left[i],right[i]);
            int water = max(0,t-h[i]);
            ans += water;
        }
    
        return ans;
    }
};