class Solution {
public:
    int countLaser(string &b){
        int count = 0;
        for(auto &ch:b){
            if(ch=='1') count++;
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        for(auto &b:bank){
            int count = countLaser(b);
            if(count != 0){
                v.push_back(count);
            }
        }

        int ans = 0;
        for(int i=1; i<v.size(); i++){
            ans += (v[i]*v[i-1]);
        }
        return ans;
    }
};