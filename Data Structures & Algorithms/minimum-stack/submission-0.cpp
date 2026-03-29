class MinStack {
public:
    stack<pair<int, int>> st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
            mini = val;
        }
        else{
            mini = min({val, st.top().second});
            st.push({val, mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
