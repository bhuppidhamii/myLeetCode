class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        vector<pair<int,int>> vp;
        // freq, number;
        for(auto i:m){
            vp.push_back({i.second, i.first});
        }

        sort(vp.begin(), vp.end(),[&](auto a, auto b){
            if(a.first == b.first){
                return a.second > b.second;
            }else{
                return a.first < b.first;
            }
        });
        vector<int>ans;
        for(auto i:vp){
            for(int j=0;j<i.first;j++){
                ans.push_back(i.second);
            }
        }
        return ans;
    }
};