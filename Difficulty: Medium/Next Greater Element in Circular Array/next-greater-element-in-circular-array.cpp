class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // Jai Shri Ram
        
        int N = arr.size();
        stack<int>st;
        vector<int> ans(N, -1);
        
        // 1st pass
        for(int i=0; i<N; i++){
            while(st.size() > 0 && arr[i] > arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        // 2nd pass
        for(int i = 0; i < N; i++){
            while(st.size() > 0 && arr[i] > arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
        }
        return ans;
    }
};