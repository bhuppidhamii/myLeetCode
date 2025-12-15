class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long result = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i] == prices[i - 1] - 1) {
                count++;
            } else {
                count = 1;
            }
            result += count;
        }
        return result;
    }
};