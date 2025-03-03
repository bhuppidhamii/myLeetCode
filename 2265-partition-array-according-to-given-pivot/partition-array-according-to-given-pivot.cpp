class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // bf
        vector<int>less;
        vector<int>greater;
        int count=0;
        for(auto &n:nums){
            if(n<pivot){
                less.push_back(n);
            }else if(n==pivot){
                count++;
            }else{
                greater.push_back(n);
            }
        }
        while(count--){ // equal
            less.push_back(pivot);
        }
        for(auto &n:greater){
            less.push_back(n);
        }
        return less;
    }
};