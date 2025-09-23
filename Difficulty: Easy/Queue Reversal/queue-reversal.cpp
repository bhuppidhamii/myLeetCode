class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // Jai Shri Ram
        
        // insert q elements in stack
        stack<int>st;
        while(q.size() > 0){
            st.push(q.front());
            q.pop();
        }
        
        // insert stack elements back to q
        while(st.size() > 0){
            q.push(st.top());
            st.pop();
        }
    }
};