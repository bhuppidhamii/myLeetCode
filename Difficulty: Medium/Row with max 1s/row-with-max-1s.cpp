// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // Jai Shri Ram
        int n = arr.size();
        int ansRow = -1;
        int maxOnes = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int>a = arr[i];
            
            // find uppper bound of 1 in a
            auto upper = upper_bound(a.begin(), a.end(), 1);
            // find lower bound of 1 in a
            auto lower = lower_bound(a.begin(), a.end(), 1);
            // count no of 1's
            int count = upper-lower;

            if(count != 0 && count > maxOnes){
                maxOnes = count;
                ansRow = i;
            }
        }
        return ansRow;
    }
};