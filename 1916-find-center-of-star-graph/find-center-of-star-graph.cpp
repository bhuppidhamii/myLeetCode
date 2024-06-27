class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(auto e:edges){
          mp[e[0]]++;
          mp[e[1]]++;
        }
        int n=mp.size();
        for(auto i:mp){
          if(i.second==n-1){
            return i.first;
          }
        }
        return 0;
    }
};