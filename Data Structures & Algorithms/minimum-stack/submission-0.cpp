class MinStack {
public:
stack<int>st,mnstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mnstack.size() == 0)
        {
            mnstack.push(val);
        }
        else 
        {
            int top = mnstack.top();
            if(val <= top) mnstack.push(val);
        }
    }
    
    void pop() {
        int top = st.top();
        int topp = mnstack.top();
        st.pop();
        if(top == topp) mnstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnstack.top();
    }
};
