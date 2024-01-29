class MyQueue {
public:
    stack<int> input, output;
    int peekEle = -1;
    MyQueue() {}

    void push(int x) {
        if (input.size() == 0) {
            peekEle = x;
        }
        input.push(x);
    }

    int pop() {
        if (output.size() == 0) {
            // input -> output 0n
            while (input.size() != 0) {
                output.push(input.top());
                input.pop();
            }
        }
        int top = output.top();
        output.pop();
        return top;
    }

    int peek() {
        if (output.size() > 0) {
            return output.top();
        } else {
            return peekEle;
        }
    }

    bool empty() { return output.empty() && input.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */