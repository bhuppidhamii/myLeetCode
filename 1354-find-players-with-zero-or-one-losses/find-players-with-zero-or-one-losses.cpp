class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<pair<int,int>>m;
        for(auto i:matches){
            int winner=i[0];
            int loser=i[1];
            m.push_back({winner,loser});
        }

        map<int,int>winners;
        for(auto i:m){
            winners[i.first]++;
        }

        map<int,int>losers;
        for(auto i:m){
            losers[i.second]++;
        }

        vector<int>NotlostanyMatch;
        for(auto i:winners){
            if(losers.find(i.first)==losers.end()){
                NotlostanyMatch.push_back(i.first);
            }
        }

        vector<int>lostoneMatch;
        for(auto i:losers){
            if(i.second==1){
                lostoneMatch.push_back(i.first);
            }
        }

        for(auto i:NotlostanyMatch){
            cout<<i<<" ";
        }
        cout<<"\n";
        for(auto i:lostoneMatch){
            cout<<i<<" ";
        }
        vector<vector<int>>answer;
        answer.push_back(NotlostanyMatch);
        answer.push_back(lostoneMatch);
        return answer;
    }
};