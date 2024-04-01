class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int l = 0;
        while (ss >> word) {
            l = word.length();
        }
        return l;
    }
};