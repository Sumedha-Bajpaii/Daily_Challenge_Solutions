class Solution {
public:
    
    int brokenCalc(int sv, int tv) {
        
        if(sv >= tv)
            return sv-tv;
        
        if(tv%2==0)
            return 1 + brokenCalc(sv,tv/2);
        else
            return 1 + brokenCalc(sv,tv+1);
         
    }
};