class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here - bf
        vector<int>v;
        for(auto &i:matrix){
            for(auto &j:i){
                v.push_back(j);
            }
        }
        sort(begin(v), end(v));
        return v[k-1];
    }
};