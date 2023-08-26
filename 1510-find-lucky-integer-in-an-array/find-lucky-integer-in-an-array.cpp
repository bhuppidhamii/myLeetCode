class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>m;
        for(auto i:arr){
            m[i]++;
        }
        int lucky = -1;
        for(auto i:arr){
            if(i == m[i]){
                lucky=max(lucky,i);
            }
        }
        return lucky;
    }
};