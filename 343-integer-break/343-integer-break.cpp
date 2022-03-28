class Solution {
public:
    int f(int i, int targ)
    {
        if(targ==0 || i==0)
            return 1;
        
        int take = 1;
        if(i<=targ){
            take = i*f(i,targ-i);
        }
        int notTake = f(i-1,targ);
        return max(take,notTake);
    }
    
    int integerBreak(int n) 
    {
        
        return f(n-1,n);
    }
};