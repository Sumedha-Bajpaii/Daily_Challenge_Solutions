class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int ans = 1;    //for n==0
        for(int d=1; d<=n; d++){
            int temp = 9;
            for(int i=2; i<=d; i++){
                temp *= 9-i+2;
            }
            //cout<<temp<<" ";
            ans += temp;
        }
        return ans; 
    }
};