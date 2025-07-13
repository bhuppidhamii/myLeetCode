class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));

        sort(begin(trainers), end(trainers));

        int i = 0;
        for (int j = 0; i < players.size() && j < trainers.size(); j++) {
            if (players[i] <= trainers[j]) {
                i++;
            }
        }
        return i;
    }
};