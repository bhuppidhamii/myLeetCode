class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        unordered_map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
            if (mp[i] > maxFreq) {
                maxFreq = mp[i];
            }
        }

        int count = 0;
        for (auto& i : mp) {
            if (i.second == maxFreq) {
                count += i.second;
            }
        }
        return count;
    }
};