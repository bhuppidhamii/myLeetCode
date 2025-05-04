class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> freq(100, 0);
        int count = 0;
        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            if (a > b) {
                swap(a, b);
            }
            int num = (a * 10) + b;
            if (freq[num] != 0) {
                count += freq[num];
            }
            freq[num]++;
        }
        return count;
    }
};