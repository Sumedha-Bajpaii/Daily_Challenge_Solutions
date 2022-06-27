class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        int i=0, n=h.size();
        long long sumHeap=0, sumTotal=0;
        priority_queue<int, vector<int>, greater<int>> heap;
        
        while(i < n-1){
            int gap = h[i+1] - h[i];
            
            if(gap<=0){
                i++;
            }
            else{
                sumTotal += gap;
                
                heap.push(gap);
                sumHeap += gap;
                
                if(heap.size()>ladders){
                    sumHeap -= heap.top();
                    heap.pop();
                }
                
                if( (sumTotal - sumHeap) <= bricks)
                    i++;
                else
                    break;
            }
        }
        
        return i;
        
    }
};