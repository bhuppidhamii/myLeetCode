class Solution {
public:
    int countLargestGroup(int n) {
        int largestSize = 0;
        map<int, vector<int>> mp;
        // sum, group
        for (int i = 1; i <= n; i++) {
            int n = i, sum = 0;
            while (n > 0) {
                sum += (n % 10);
                n /= 10;
            }
            mp[sum].push_back(i);
            largestSize = max(largestSize, (int)mp[sum].size());
        }

        int count = 0;
        for (auto& i : mp) {
            if (i.second.size() == largestSize) {
                count++;
            }
        }
        return count;
    }
};