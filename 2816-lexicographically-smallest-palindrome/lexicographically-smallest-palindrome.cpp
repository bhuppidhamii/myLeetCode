class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l=s.size();
        int i=0, j=l-1;

        while(i<j){
            char s1=s[i], s2=s[j];

            if(s1 != s2){
               char c = min(s1, s2);
               s[i] = s[j] = c;
            }
            i++, j--;
        }
        return s;
    }
};