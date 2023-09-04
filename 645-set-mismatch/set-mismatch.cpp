class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dupNum=0;
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second == 2){
                dupNum=i.first;
                break;
            }
        }

        int nSum=0;
        for(int i=1;i<=nums.size();i++){
            nSum+=i;
        }

        int numsSum=0;
        for(auto i:m){
            numsSum+=i.first;
        }

        return {dupNum, nSum-numsSum};
    }
};