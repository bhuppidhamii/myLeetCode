class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int l = arr.size();
        
        // Initialize majority elements
        int maj1 = -1, maj2 = -1;
        int count1 = 0, count2 = 0;

        // Finding potential candidates
        for (int num : arr) {
            if (num == maj1) {
                count1++;
            } else if (num == maj2) {
                count2++;
            } else if (count1 == 0) {
                maj1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Validate the candidates
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == maj1) count1++;
            else if (num == maj2) count2++; // Avoid double counting
        }

        vector<int> res;
        if (count1 > l / 3) res.push_back(maj1);
        if (count2 > l / 3) res.push_back(maj2);

        return res;
    }
};