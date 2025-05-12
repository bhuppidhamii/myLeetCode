class Solution {
public:
    set<int> result;  // to avoid duplicates
    int N;

    void solve(vector<int>& digits, vector<bool>& used, int num, int count) {
        if (count == 3) {
            if (num >= 100 && num % 2 == 0) {
                result.insert(num);
            }
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (used[i]) continue;

            // Skip leading 0
            if (count == 0 && digits[i] == 0) continue;

            used[i] = true;
            solve(digits, used, num * 10 + digits[i], count + 1);
            used[i] = false;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        N = digits.size();
        vector<bool> used(N, false);
        solve(digits, used, 0, 0);

        return vector<int>(result.begin(), result.end());
    }
};