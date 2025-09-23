class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101, 0);

        int maxFreq = 0;
        int total = 0;
        for (auto& n : nums) {
            count[n]++;

            int freq = count[n];
            if (freq > maxFreq) {
                maxFreq = freq;
                total = maxFreq;
            } else if (freq == maxFreq) {
                total += maxFreq;
            }
        }
        return total;
    }
};