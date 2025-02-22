class MyQueue {
    private:
    stack<int> q;
    stack<int> st;
public:
    MyQueue() {}
    
    void push(int x) {
        while(!q.empty()) {
            int top = q.top();
            st.push(top);
            q.pop();
        }
        st.push(x);
        while(!st.empty()) {
            int top = st.top();
            q.push(top);
            st.pop();
        }
    }
    
    int pop() {
        int top = q.top();
        q.pop();
        return top;
    }
    
    int peek() {
        int top = q.top();
        return top;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */