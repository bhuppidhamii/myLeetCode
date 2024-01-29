class MyQueue {
public:
    stack<int> st;
    MyQueue() {}

    void push(int x) {
        if (st.empty() == true) {
            st.push(x);
        } else {
            int top = st.top();
            st.pop();
            push(x);
            st.push(top);
        }
    }

    int pop() {
        int top=st.top();
        st.pop();
        return top;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
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