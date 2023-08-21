class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss=s+s;
        string subString=ss.substr(1, ss.length()-2);

        if(subString.find(s) != string::npos){
            return true;
        }else{
            return false;
        }
    }

};