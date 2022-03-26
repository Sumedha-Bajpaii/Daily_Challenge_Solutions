class Solution {
public:
    int halveArray(vector<int>& a) {
        
        priority_queue<double> mh;
        
        double sum=0;
        
        for(auto i : a){
            sum += i;
            mh.push(i);
        }
       
        int cnt=0;
        double rSum=sum;
        
        while(rSum > sum/2.0){
            double p = mh.top();
            mh.pop();
            p = p/2.0;
            rSum -= p;
            mh.push(p);
            cnt++;
        }
        
        return cnt;
    }
};