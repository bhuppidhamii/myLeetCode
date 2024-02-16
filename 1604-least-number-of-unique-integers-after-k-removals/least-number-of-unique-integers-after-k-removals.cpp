class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for (auto i : m) {
            pq.push({i.second, i.first});
        }

        while (k > 0 && !pq.empty()) {
            int freq = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            if (k >= freq) {
                k -= freq;
            } else {
                pq.push({freq - k, num});
                k = 0;
            }
        }

        return pq.size();
    }
};
