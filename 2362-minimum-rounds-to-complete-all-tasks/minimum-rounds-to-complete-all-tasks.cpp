class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for (auto& t : tasks) {
            mp[t]++;
        }
        int rounds = 0;
        for (auto& [num, count] : mp) {
            if (count == 1)
                return -1;

            rounds += ceil((double)count / 3);
        }
        return rounds;
    }
};