// at each step we have 2 options
// paste   --> operation += 1   --> len += prev
// copy paste  --> operation += 2   --> len += len

class Solution {
public:
    int f(int len, int prev, int n){
        if(len > n)
            return 1e9;
        if(len == n)
            return 0;
        
        int p = 1 + f(len+prev, prev, n);
        int cp = 2 + f(len+len, len, n);
        return min(p,cp);
    }
    
    int minSteps(int n) {
        if(n==1)    return 0;
        return 1 + f(1,1,n);
    }
};





//copy copy F
//copy paste T
//paste paste T
//paste copy T

class Solution1 {
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