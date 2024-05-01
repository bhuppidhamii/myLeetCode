class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word.find(ch) == string::npos) {
            return word;
        }
        int idx = word.find(ch);
        string str = word.substr(0, idx + 1);
        reverse(str.begin(), str.end());

        return str + word.substr(idx + 1);
    }
};