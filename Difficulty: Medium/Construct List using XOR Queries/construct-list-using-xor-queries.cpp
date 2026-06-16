class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &q) {
        // Jai Shri Ram
        int l = q.size();
        vector<int>v;
        int cumXor = 0;
        for(int i=l-1; i>=0; i--){
            if(q[i][0] == 1){
                cumXor = cumXor ^ q[i][1];
            }else{
                v.push_back(cumXor xor q[i][1]);
            }
        }
        v.push_back(cumXor xor 0);
        sort(begin(v), end(v));
        return v;
    }
};
