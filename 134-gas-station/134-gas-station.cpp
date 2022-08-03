class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int tank=0, start=0, i=0, n=gas.size(), round=0, done=1;
        
        while(1){
            if(i==0) round++;
            if(round==3) return -1;
            
            tank += gas[i];
            tank -= cost[i];
            
            if(tank < 0){   //i can not be start
                tank = 0;
                start = (i+1)%n;
            }
            else if((i+1)%n==start){
                return start;
            }
            
            i = (i+1)%n;
        }
        
        return 0;
    }
};