class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int N = nums.size();
        // a = b*q + r
        // a % b = r (gets original)
        // a / b = q (gets new)
        for (int i = 0; i < N; i++) {
            // convert into an combined format
            int old_num = nums[i];
            cout<<"old_num "<<old_num<<"\n";
            int new_num = nums[nums[i]];
            cout<<"new_num "<<new_num<<"\n";

            nums[i] = old_num + N * (new_num % N);
            cout<<"combined_num "<<nums[i]<<"\n";
            cout<<"\n";
        }

        for (int i = 0; i < N; i++) {
            nums[i] = nums[i] / N;
        }
        return nums;
    }
};