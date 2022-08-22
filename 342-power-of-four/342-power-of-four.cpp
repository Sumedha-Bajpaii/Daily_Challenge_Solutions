// one     1
// zero    even times   

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<0)
            return false;
        //long n = x;
        // n = abs(n);
        
        int one=0, zero=0;
        
        while(n){

            if(n&1){
                one++;
            }
            else{
                zero++;
            }
            
            n = n/2;
        }
        
        if(one==1 && zero%2==0)
            return true;
        return false;
    }
};