class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // differnce array technique
        vector<int> diff(n + 1, 0);
        for (auto& b : bookings) {
            int l = b[0];
            int r = b[1];
            int x = b[2];

            diff[l] += x;
            if (r + 1 < n + 1) {
                diff[r + 1] -= x;
            }
        }
        
        vector<int> ans(n, 0);
        int cumSum = diff[1];
        ans[0] = cumSum;
        for (int i = 2; i <= n; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
            ans[i - 1] = cumSum;
        }

        return ans;
    }
};