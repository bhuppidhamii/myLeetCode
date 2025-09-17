class Solution {
  public:
    string decodedString(string &s) {
        // Jai Shri Ram 🙏
        
        stack<char>st;
        
        for(auto &ch:s){
            if(ch == ']'){
                // 1. jab tk num na aaye pop krke str banao
                string str = "";
                while(st.size() > 0 && isdigit(st.top()) == false){
                    if(st.top() == '[' ){ // do no add  the '['
                        st.pop();
                        continue;
                    }
                    str+=st.top();
                    st.pop();
                }
                
                // 2. reverse kro
                reverse(begin(str), end(str));

                // k times kro string ko
                string digit = "";
                while(st.size() > 0 && isdigit(st.top()) == true){
                    digit+=st.top();
                    st.pop();
                }
                reverse(begin(digit), end(digit));
                int n = stoi(digit);
                
                string str2 = "";
                for(int i=0; i<n; i++){
                    str2+=str;
                }
                
                // then wapas push kr do stack m
                for(auto &ch:str2){
                    st.push(ch);
                }
            }else{
                st.push(ch); // push no matter what
            }
        }
        string ans = "";
        while(st.size() > 0){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};