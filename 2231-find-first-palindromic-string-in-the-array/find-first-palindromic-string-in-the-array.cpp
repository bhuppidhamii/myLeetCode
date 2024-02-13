class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto w : words) {
            string s1 = w;
            reverse(s1.begin(), s1.end());
            if (s1 == w) {
                return w;
            }
        }
        return "";
    }
};