class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // remove the duplicates
        vector<int> arr;
        int curr=0;
        for (auto& i : nums) {
            if(i != curr){
                curr = i;
                arr.push_back(i);
            }
        }

        // count hill & valley
        int hill = 0, valley = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                hill++;
            } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                valley++;
            }
        }

        return hill + valley;
    }
};