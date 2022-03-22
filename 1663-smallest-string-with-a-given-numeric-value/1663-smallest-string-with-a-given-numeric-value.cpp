class Solution {
public:
    string getSmallestString(int n, int k) {
        
        
        vector<int> v(n,1);
        int sum=n, i=n-1;
        
        int rem = k-sum;
        
        while(rem>0){
            if(rem > 25){
                v[i] += 25;
                rem -= 25;
            }
            else{
                v[i] += rem;
                rem = 0;
            }
            i--;
        }
        
        string res = "";
        for(auto d : v){
            res += char(96+d);
        }
        
        return res;
    }
};