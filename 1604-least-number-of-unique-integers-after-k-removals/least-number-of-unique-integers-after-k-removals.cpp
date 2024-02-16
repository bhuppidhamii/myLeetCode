class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }

        vector<int> freq;
        for (auto i : m) {
            freq.push_back(i.second);
        }
        sort(begin(freq), end(freq));

        for (int i = 0; i < freq.size(); i++) {
            k -= freq[i];
            if (k < 0) {
                return freq.size() - i;
            }
        }
        return 0;
    }
};
