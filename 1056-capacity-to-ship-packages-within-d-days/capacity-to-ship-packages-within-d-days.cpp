class Solution {
public:
    bool check(vector<int>& weights, int days, int mid) {
        int d = 0, sum = 0, N = weights.size();
        int i = 0;
        while (i < N) {
            int j = i;
            while (j < N && sum + weights[j] <= mid) {
                sum += weights[j++];
            }
            i = j;
            d++;
            sum = 0;
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};