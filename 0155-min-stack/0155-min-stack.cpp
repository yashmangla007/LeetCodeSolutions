class MinStack {
private: 
    stack<int> st;
    stack<int> stmin;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(stmin.empty()){
            stmin.push(value);
        }
        else if(value<=stmin.top()){
            stmin.push(value);
        }
        return;
    }
    
    void pop() {
        if(stmin.top() == st.top()){
            stmin.pop();
        }
        st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */