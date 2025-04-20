class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        // size, peoples
        int N = groupSizes.size();
        for (int i = 0; i < N; i++) {
            mp[groupSizes[i]].push_back(i);
            // size --> peoples
        }

        // for(auto &i:mp){
        //     cout<<i.first<<" - ";
        //     for(auto &n:i.second){
        //         cout<<n<<" ";
        //     }
        //     cout<<"\n";
        // }

        vector<vector<int>> ans;
        for (auto& i : mp) {
            int size = i.first;
            vector<int> v;
            vector<int> peoples = i.second;
            for (int idx = 0; idx < peoples.size(); idx++) {
                // cout<<peoples[idx];
                v.push_back(peoples[idx]);
                if (v.size() == size) {
                    ans.push_back(v);
                    v.erase(v.begin(),v.end());
                }
            }
        }
        return ans;
    }
};