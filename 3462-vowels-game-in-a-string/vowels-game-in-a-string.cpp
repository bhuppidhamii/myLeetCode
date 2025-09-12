class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(begin(s), end(s), [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        });
    }
};