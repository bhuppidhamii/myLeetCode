class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>kIndices;
        int N=nums.size();
        for(int i=0; i<N; i++){
            if(nums[i] == key){
                kIndices.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0; i<N; i++){
            int num=nums[i];
            //find k-index
            for(int j=0; j<kIndices.size(); j++){
                if(abs(i-kIndices[j]) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};