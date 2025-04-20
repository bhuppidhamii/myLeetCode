class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        int N = groupSizes.size();
        vector<vector<int>> res;

        for (int i = 0; i < N; i++) {
            int size = groupSizes[i];
            mp[size].push_back(i);

            if (mp[size].size() == size) {
                res.push_back(mp[size]);
                mp.erase(size);
            }
        }

        return res;
    }
};