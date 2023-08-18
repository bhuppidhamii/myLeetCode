class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        if(nums.size()==1){
            return {0,1};
        }
        int pair=0;
        int left=0;
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second % 2 == 0){
                pair += i.second/2;
            }else{
                pair += i.second/2;
                left += i.second%2;
            }
        }
        

        return {pair, left};
    }
};