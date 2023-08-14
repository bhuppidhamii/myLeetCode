class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto i:words){
            m[i]++;
        }
        vector<pair<int,string>>vp;
        for(auto i:m){
            vp.push_back({i.second, i.first});
        }
        sort(vp.begin(),vp.end(),[&](auto a,auto b){
            if(a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }

        });

        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].second);
        }
        return ans; 
    }
};