//copy copy F
//copy paste T
//paste paste T
//paste copy T

class Solution {
public:
    int f(int curLen, int lastCopied, char lastOp, int n){
        
        if(curLen == n)
            return 0;
        if(curLen > n)
            return 1e9;
        
        int x=1e9,y=1e9,z=1e9;
        
        if(lastOp == 'c'){
            x = 1 + f(curLen+lastCopied, lastCopied, 'p', n);   //copy -> paste
        }
        if(lastOp == 'p'){
            y = 1 + f(curLen+lastCopied, lastCopied, 'p', n);   //paste -> paste
            z = 1+ f(curLen, curLen, 'c', n);                  //paste ->copy
        }
        
        return min({x,y,z});
    }
    
    int minSteps(int n) {
        
        if(n==1)
            return 0;
        int res = 1 + f(1,1,'c',n);
        return res;   //+1 for initial copy operation
    }
};