class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int res=0;
        for(int i=1;i<n;i++){
            int a=s[i-1]-'a';
            int b=s[i]-'a';
            int diff=abs(a-b);
            res+=diff;
        }
        return res;
    }
};