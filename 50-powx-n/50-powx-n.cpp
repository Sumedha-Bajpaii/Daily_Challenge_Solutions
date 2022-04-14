class Solution {
public:
    double f(double x, long n){
        
        if(n<0)
            return f(1/x,-n);
        if(n==0)
            return 1;
        
        double val = f(x,n/2);
        
        if(n%2 == 0)
            return val*val;
        else
            return val*val*x;
    }
    
    double myPow(double x, int n) {
        
        return f(x,n);
    }
};