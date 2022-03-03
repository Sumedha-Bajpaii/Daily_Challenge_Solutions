class Solution {
public:
    int count(int l, int r){
        int cnt=0;
        int len = r-l+1;
        
        for(int subarrayLen=3; subarrayLen<=len; subarrayLen++){
            cnt+= len - subarrayLen +1;
        }
        return cnt;
    }
    
    int numberOfArithmeticSlices(vector<int>& a) {
        
        int ans = 0, n=a.size();
        if(n<3)
            return 0;
        
        int i=0;
        int diff = a[i+1]-a[i];
        int j=i+2;
        
        while(j<n){
            if(a[j]-a[j-1] == diff)
                j++;
            
            else{
                ans += count(i,j-1);
                i = j-1;
                if(i<n-2){
                    diff = a[i+1]-a[i];
                    j=i+2;
                }
                else
                    break;
            }
        }
        ans += count(i,j-1);
        return ans;
    }
};