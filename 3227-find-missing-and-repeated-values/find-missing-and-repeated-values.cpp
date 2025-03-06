class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int a, b;
        int ogSum = 0, currSum = 0;
        int n = 1;
        for (auto& arr : grid) {
            for (auto& i : arr) {
                if (mp.find(i) != mp.end()) {
                    a = i;
                }
                mp[i]++;
                ogSum += n;
                n++;
                currSum += i;
            }
        }
        b = (ogSum - currSum) + a;
        return {a, b};
    }
};