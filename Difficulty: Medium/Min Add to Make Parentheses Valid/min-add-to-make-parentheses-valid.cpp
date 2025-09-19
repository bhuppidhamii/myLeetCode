class Solution {
  public:
    int minParentheses(string& s) {
        // Jai Shri Ram
        
        string res = "";
        
        for(auto &ch : s){
            if(ch == ')'){
                // if res.back() == '('
                if(res.size() > 0 && res.back() == '('){
                    res.pop_back();
                }else{
                    res+=ch;
                }
            }else{
                res+=ch;
            }
        }
        return (int)res.size();
    }
};