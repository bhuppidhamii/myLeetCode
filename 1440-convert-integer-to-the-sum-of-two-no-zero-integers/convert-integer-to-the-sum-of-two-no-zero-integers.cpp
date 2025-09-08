class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            int a = i;
            int b = n - a;
            // a and b does not contains 0
            if (to_string(a).find_first_of('0') == string::npos &&
            to_string(b).find_first_of('0') == string::npos) {
                return {a, b};
            }
        }
        return {};
    }
};