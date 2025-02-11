class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int n = part.size();
        for (auto& ch : s) {
            result.push_back(ch);

            if (result.size() >= n && result.substr(result.size() - n) == part) {
                result.erase(result.size() - n);
            }
        }
        return result;
    }
};