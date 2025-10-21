class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Jai Shri Ram
        unordered_map<int,int>mp;
        for(auto &i:arr){
            mp[i]++;
        }
        
        // vector of pair
        vector<pair<int, int>>vp;
        for(auto &i:mp){
            int num = i.first;
            int freq = i.second;
            vp.push_back({freq, num});
        }
        
        // custom sort
        sort(begin(vp), end(vp),[](auto &a, auto &b){
           if(a.first == b.first){
               return a.second > b.second;
           } 
          return a.first > b.first; // greater freq comes first
        });
        
        vector<int>ans;
        for(int i=0; i<vp.size() && k--; i++){
            ans.push_back(vp[i].second);
        }
        
        return ans;
    }
};
