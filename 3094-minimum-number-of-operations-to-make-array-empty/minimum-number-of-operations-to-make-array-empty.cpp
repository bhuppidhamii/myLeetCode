class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        for (auto i : m) {
            if (i.second == 1) {
                return -1;
            }
        }

        int count = 0;
        while (m.size() > 0) {
            cout<<m.size()<<" ";
            for (auto i : m) {
                int num = i.first;
                int freq = i.second;
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