class Solution {
public:
    void f(int t, vector<int>& res, int n){
        
        if(t>n)   return;
        res.push_back(t);
        
        for(int i=0; i<=9; i++){
            int d = t*10+i;
            f(d,res,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> res;
        for(int t=1; t<=9; t++){
            f(t,res,n);
        }
        return res;;
    }
};