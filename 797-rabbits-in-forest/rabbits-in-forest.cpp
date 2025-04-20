class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;

        for (auto& x : answers) {
            mp[x]++;
        }

        int total = 0;
        for (auto& i : mp) {
            int x = i.first;      // answer
            int count = i.second; // kitne logo ne x ans kiya;

            int groupSize = (x + 1);
            int group = ceil((double)count / groupSize);

            int totalRabbits = group * groupSize;
            total += totalRabbits;
        }
        return total;
    }
};