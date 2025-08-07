class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        // take 00:00 as a reference point
        for (auto& t : timePoints) {
            string time = t;
            int h = stoi(time.substr(0, 2));
            h = h * 60;

            int m = stoi(time.substr(3, 2));

            int totalMins = h + m;
            minutes.push_back(totalMins);
        }

        sort(minutes.begin(), minutes.end());
        // for (auto& i : minutes) {
        //     cout << i << " ";
        // }

        int mini = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            int diff = minutes[i] - minutes[i - 1];
            mini = min(mini, diff);
        }

        // Also consider the circular difference (across midnight)
        int firstLastDiff = 1440 - (minutes.back() - minutes.front());
        mini = min(mini, firstLastDiff);

        return mini;
    }
};