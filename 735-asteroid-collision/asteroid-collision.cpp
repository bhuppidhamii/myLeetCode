class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto& i : asteroids) {

            while (!ans.empty() && ans.back() > 0 && i < 0) {
                int sum = ans.back() + i;
                if(sum < 0){
                    ans.pop_back();
                }else if(sum > 0){
                    i=0;
                }else{ // sum == 0
                    ans.pop_back();
                    i=0;
                }
            }

            if (i != 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};