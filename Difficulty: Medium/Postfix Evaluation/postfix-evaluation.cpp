class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // Jai Shri Ram
        
        stack<int>st;
        
        for(auto &s:arr){
            // whenever an operand comes, pop 2 elements from the stack
            // and apply the operation to them &
            // push the result
            if(s == "+" || s=="-" || s=="*" || s=="/" || s=="^"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                int res = 0;
                if(s == "+"){
                    res = a + b;
                }else if(s == "-"){
                    res = a - b;
                }else if(s == "*"){
                    res = a * b;
                }else if(s == "/"){
                    double ans = double(a) / double(b);
                    // cout<<ans;
                    res = (int)floor(ans);
                    // cout<<res;
                }else if(s == "^"){
                    res = (int)pow(a, b);
                }
                st.push(res);    
            }else{
                int n = stoi(s); // convert to integer
                st.push(n); // push to stack
            }
        }
        return st.top();
    }
};