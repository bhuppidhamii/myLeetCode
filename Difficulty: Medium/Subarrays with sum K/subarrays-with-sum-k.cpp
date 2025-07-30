class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // Jai Shri Ram
        int sum = 0;
        map<int,int>mp;
        mp[0] = 1;
        int count = 0;
        for(auto &i:arr){
            sum+=i;
            if(mp.find(sum-k) != mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};