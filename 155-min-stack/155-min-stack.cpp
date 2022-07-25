class MinStack {
    stack<int> st;
    stack<pair<int,int>> mins;
    
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        
        if(mins.empty() || mins.top().first>val){
            mins.push({val,1});
        }
        else if(mins.top().first == val){
            mins.top().second++;
        }
        
    }
    
    void pop() {
        int t = st.top();
        st.pop();
        
        if(mins.top().first == t)
            mins.top().second--;
        
        if(mins.top().second==0)
            mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top().first;
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