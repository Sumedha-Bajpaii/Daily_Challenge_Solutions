class Solution {
public:
    long long int count(vector<int>& a,long long int givenTime){
        long long int tt=0;
        for(auto i: a){
            tt += givenTime/i;
        }
        return tt;
    }
    
    long long minimumTime(vector<int>& time, int reqTrips) {
        
        long long int lo=0, hi=1e14;
        
        while(lo<hi){
            long long int mid = (lo+hi)/2;
            //total trips possible in given time mid
            long long int totalTrips = count(time,mid);   
            if(totalTrips < reqTrips)
                lo = mid+1;
            else
                hi = mid;
        }
        return hi;
    }
};