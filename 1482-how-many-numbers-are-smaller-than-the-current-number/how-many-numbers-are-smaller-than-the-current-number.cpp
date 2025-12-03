class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>freq(501,0);
        for(auto &i:nums){
            freq[i]++;
        }

        vector<int>temp(501,0);
        int count = 0;
        for(int i=0;i<501;i++){
            temp[i]=count;
            count+=freq[i];
        }

        for(int i=0; i<nums.size(); i++){
            nums[i] = temp[nums[i]];
        }
        return nums;
    }
};