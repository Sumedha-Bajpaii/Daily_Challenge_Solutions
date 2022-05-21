class Solution {
public:
    bool possible(int rate, vector<int>& piles, int h){
        
        int total = 0;
 
        for(int p: piles){
            int r = ceil(p/(1.0*rate));
            total += r;
        }
        return total<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        //rates
        int lo=1, hi=0;
        
        for(int x: piles){
            if(x>hi)
                hi = x;
        }
        
        int ans=0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(possible(mid,piles,h)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};