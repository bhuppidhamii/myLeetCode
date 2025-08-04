
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = fruits.size();
        int ans=0, idx=0;
        unordered_map<int,int> m;

        for(int i=0; i<l; i++){
            m[fruits[i]]++;

            while(m.size() > 2){

                if(m[fruits[idx]]==1){
                    m.erase(fruits[idx]);
                }else{
                    m[fruits[idx]]--;
                }
                idx++;
            }
            // if(i-idx+1 > ans){
            //     ans = i-idx+1;
            // } 
            ans=max(ans, i-idx+1);
        }
        return ans;
    }
};

