class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if (l1 != l2) return false;

        // jo char word1 m h vo char word2 m bhi hona chahiye!
        // frequencies bhi same honi chahiye!

        map<char, int> m1;
        for (auto ch : word1) {
            m1[ch]++;
        }

        map<char, int> m2;
        for (auto ch : word2) {
            m2[ch]++;
        }

        vector<int> freq1;
        for (auto i : m1) {
            char ch = i.first;
            freq1.push_back(i.second);
            if (m2.find(ch) == m2.end()) {
                return false;
            }
        }

        vector<int> freq2;
        for (auto i : m2) {
            freq2.push_back(i.second);
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return freq1 == freq2;
    }
};