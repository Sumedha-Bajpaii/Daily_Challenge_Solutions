class Solution {
public:
    long long s(long long a, long long n){
        return (n* (2L*a + (n-1) ) )/2;
    }
    
    long long minimalKSum(vector<int>& A, int k) {
        long long ans=0;
        sort(A.begin(),A.end());
        int p,cnt,n=A.size();
        long long sum;
        
        p = 1;
        for(int j=0; j<n && k>0; j++){
            cnt = A[j]-p;
            
            if(cnt<=0){
                p = A[j]+1;
                continue;
            }
            sum = s(p,min(k,cnt));
            ans += sum;
            k -= min(k,cnt);
            if(k==0)
                break;
            p = A[j]+1;
        }
        
        if(k>0){
            sum = s(p,k);
            ans += sum;
        }
        
        return ans;
    }
};