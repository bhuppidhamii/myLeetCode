class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less;
        vector<int>equal;
        vector<int>greater;

        for(auto i:nums){
            if(i < pivot){
                less.push_back(i);
            }else if(i == pivot){
                equal.push_back(i);
            }else{
                greater.push_back(i);
            }
        }
        vector<int>res;
        if(less.size()>0){
            for(auto i:less){
                res.push_back(i);
            }
        }

        if(equal.size()>0){
            for(auto i:equal){
                res.push_back(i);
            }
        }

        if(greater.size()>0){
            for(auto i:greater){
                res.push_back(i);
            }
        }

        return res;
    }
};