class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> v;

        for (auto& n : nums) {
            int digitSum = sumDigits(n);
            v.push_back({digitSum, n});
        }
        sort(begin(v), end(v));

        int result = -1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first == v[i - 1].first) {
                result = max(result, v[i].second + v[i - 1].second);
            }
        }
        return result;
    }
};