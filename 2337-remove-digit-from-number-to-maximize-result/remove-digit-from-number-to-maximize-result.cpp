class Solution {
public:
    string removeDigit(string s, char digit) {
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]==digit && s[i+1]-'0' > s[i]-'0'){
                return s.substr(0, i) + s.substr(i + 1);
            }
        }
        int last_idx=s.rfind(digit);
        return s.substr(0, last_idx) + s.substr(last_idx + 1);
    }
};
