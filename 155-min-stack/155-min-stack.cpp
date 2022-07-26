class MinStack {
    //      element,minimum
    stack<pair<int,int>> mins;
    
public:
    MinStack() {}
    
    void push(int val) {
        
        if(mins.empty() || getMin()>val){
            mins.push({val,val});
        }
        else{
            mins.push({val,getMin()});
        }
        
    }
    
    void pop() {
        mins.pop();
    }
    
    int top() {
        return mins.top().first;
    }
    
    int getMin() {
        return mins.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */