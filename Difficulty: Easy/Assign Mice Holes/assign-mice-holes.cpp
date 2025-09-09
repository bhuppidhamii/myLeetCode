class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Jai Shri Ram
        
        int n = holes.size();
        
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int max_dist = -1;
        for(int i=0; i<n; i++){
            int dist = abs(mices[i]-holes[i]);
            if(dist > max_dist){
                max_dist = dist;
            }
        }
        return max_dist;
    }
};