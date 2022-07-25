class MinStack {
    stack<int> st;
    map<int,int> mp;
    
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int t = st.top();
        st.pop();
        mp[t]--;
        
        if(mp[t]==0){
            mp.erase(t);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mp.begin()->first;
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