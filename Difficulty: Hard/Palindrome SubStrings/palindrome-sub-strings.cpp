class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Function to expand around center and count palindromes
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len >= 2) count++; // Only length >= 2
                left--;
                right++;
            }
        };

        // Odd and even length centers
        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd length palindromes
            expand(i, i + 1); // Even length palindromes
        }

        return count;
    }
};