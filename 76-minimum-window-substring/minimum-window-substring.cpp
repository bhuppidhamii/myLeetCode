class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        int n = s.length();

        unordered_map<int, int> m;
        for (auto& i : t) {
            m[i]++;
        }

        int reqCount = t.length();
        int i = 0, j = 0;

        int minWindow_size = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];

            if (m[ch] > 0) {
                reqCount--;
            }
            m[ch]--;

            while (reqCount == 0) {
                // start shrinking the window

                int currWindowSize = j - i + 1;
                if (minWindow_size > currWindowSize) {
                    minWindow_size = currWindowSize;
                    start_i = i;
                }

                m[s[i]]++;

                if (m[s[i]] > 0) {
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        if (minWindow_size == INT_MAX) {
            return "";
        }
        return s.substr(start_i, minWindow_size);
    }
};