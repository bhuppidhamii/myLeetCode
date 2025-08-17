class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // Jai Shri Ram
        
        stable_sort(begin(arr), end(arr), [&x](auto &a, auto &b){
            return abs(a-x) < abs(b-x);
        });
    }
};