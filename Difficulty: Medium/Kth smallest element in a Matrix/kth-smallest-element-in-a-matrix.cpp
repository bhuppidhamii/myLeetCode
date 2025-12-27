class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // Jai Shri Ram
        // BF
        vector<int>v;
        for(auto &m:mat){
            for(auto &i:m){
                v.push_back(i);
            }
        }
        sort(begin(v), end(v));
        return v[k-1];
    }
};
