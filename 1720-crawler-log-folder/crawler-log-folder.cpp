class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(auto l:logs){
          if(l=="./"){}
          else if(l=="../"){
            if(!st.empty()) st.pop(); 
          }
          else st.push(l);
        }
        return st.size();
    }
};