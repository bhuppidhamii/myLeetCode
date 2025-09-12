class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        return any_of(begin(s), end(s), lambda);
    }
};