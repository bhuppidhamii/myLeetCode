class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l=s.size();
        for(int i=l/2;i>=1;i--){
            if(l % i == 0){
                int num_repeats=l/i;
                string substring=s.substr(0,i);
                string temp="";
                for(int j=0;j<num_repeats;j++){
                    temp+=substring;
                }
                if(temp == s){
                    return true;
                }
            }
        }
        return false;
    }
};