class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& n : nums) {
            mp[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& i : mp) {
            int freq = i.second;
            int num = i.first;
            pq.push({freq, num});
        }
        int count = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            int freq = p.first;
            int num = p.second;
            pq.pop();

            if (freq >= 5) {
                freq -= 3;
            } else if (freq % 3 == 0) {
                freq -= 3;
            } else if (freq % 2 == 0) {
                freq -= 2;
            } else {
                return -1;
            }
            count++;
            if (freq > 0) {
                pq.push({freq, num});
            }
        }
        return count;
    }
};