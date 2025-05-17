class Solution {
public:
    bool check(long long given_time, vector<int>& time, int totalTrips) {
        long long trips = 0;
        for (auto& t : time) {
            trips += given_time / t;
        }
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long) *min_element(begin(time), end(time)) * totalTrips;

        long ans = 0;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, time, totalTrips)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};