class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount = 0;
        for (auto i : s) {
            if (i == '1')
                oneCount++;
        }

        int n = s.length();
        vector<int> binary(n, 0);

        int left = 0;
        binary[n - 1] = 1;
        oneCount--;

        while (oneCount > 0) {
            binary[left] = 1;
            left++;
            oneCount--;
        }

        string ans = "";
        for (auto i : binary) {
            ans += to_string(i);
        }
        return ans;
    }
};