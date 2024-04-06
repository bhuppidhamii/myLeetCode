class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }else{
                if(ch==st.top()){
                    st.push(ch);
                }else if(ch==toupper(st.top()) || toupper(ch)==st.top()){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};