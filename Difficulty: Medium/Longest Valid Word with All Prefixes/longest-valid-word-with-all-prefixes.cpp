class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // Jai Shri Ram
        sort(begin(words), end(words));
        unordered_set<string>st;
        st.insert("");
        string ans = "";
        
        for(string &w:words){
            // cout<<w<<" ";
            string prefix = w.substr(0, w.length()-1);
            // cout<<prefix<<"\n";
            if(st.count(prefix)){ // check if prefix is present
                st.insert(w);
                
                if(w.length() > ans.length()){
                    ans = w;
                }else if( w.length() == ans.length()){
                    ans = min(ans, w);
                }
            }
        }
        return ans;
    }
};
