class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // Jai Shri Ram
        // BF
        map<int,int>mp;
        
        for(auto &i:arr){
            mp[i]++;
        }
        
        int idx = 0;
        for(auto &i:mp){
            for(int j=0;j<i.second; j++){
                arr[idx++]=i.first;
            }
        }
    }
};