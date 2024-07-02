class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(auto i:nums2){
          mp[i]++;
        }

        vector<int>ans;
        for(auto i:nums1){
          if(mp.find(i)!=mp.end()){
            ans.push_back(i);
            if(mp[i]==1){
              mp.erase(i);
            }else{
              mp[i]--;
            }
          }
        }
        return ans;
    }
};