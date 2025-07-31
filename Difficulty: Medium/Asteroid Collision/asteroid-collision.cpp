class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // Jai Shri Ram
        vector<int>ans;
        for(auto &i:asteroids){
            
            while(ans.size() > 0 && ans.back() > 0 && i < 0){
                int sum = ans.back()+i;
                if(sum < 0){
                    ans.pop_back();
                }else if(sum > 0){
                    i = 0; // break;
                }else { // sum == 0
                    ans.pop_back();
                    i = 0; // break
                }
            }
            if(i!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};