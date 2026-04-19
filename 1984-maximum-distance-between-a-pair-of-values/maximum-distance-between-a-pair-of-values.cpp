class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), i=0;
        int l2 = nums2.size(), j=0;
        int result = 0;
        while(i<l1 && j<l2){
            if(nums1[i] > nums2[j]){
                i++;
            }else{
                result = max(result, j-i);
                j++;
            }
        }
        return result;
    }
};