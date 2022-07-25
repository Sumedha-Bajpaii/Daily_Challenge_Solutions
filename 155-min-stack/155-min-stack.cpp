class MinStack {
    vector<int> v;
    map<int,int> mp;
    
public:
    MinStack() {}
    
    void push(int val) {
        v.push_back(val);
        mp[val]++;
    }
    
    void pop() {
        int t = v.back();
        v.pop_back();
        mp[t]--;
        
        if(mp[t]==0){
            mp.erase(t);
        }
    }
    
    int top() {
        return v.back();
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