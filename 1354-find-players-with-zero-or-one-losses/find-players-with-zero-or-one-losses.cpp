class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>losers;
        for(auto i:matches){
            losers[i[1]]++;
        }

        vector<vector<int>>ans(2);
        for(auto i:matches){
            int winner=i[0];
            int loser=i[1];
            if(losers.find(winner)==losers.end()){
                ans[0].push_back(winner);
                losers[winner]=2;
            }

            if(losers[loser]==1){
                ans[1].push_back(loser);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};