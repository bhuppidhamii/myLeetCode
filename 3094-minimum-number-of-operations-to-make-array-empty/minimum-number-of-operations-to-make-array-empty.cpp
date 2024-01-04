class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }

        int count = 0;
        while (m.size() > 0) {
            for (auto i : m) {
                int num = i.first;
                int freq = i.second;
                if (freq == 1){
                    return -1;
                }
                if (freq % 3 == 0) {
                    freq -= 3;
                } else {
                    freq -= 2;
                }
                if (freq == 0) {
                    // remove from map
                    m.erase(num);
                } else {
                    // update
                    m[num] = freq;
                }
                count++;
            }
        }
        return count;
    }
};