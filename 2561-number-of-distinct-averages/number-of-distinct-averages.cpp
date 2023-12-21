class Solution {
public:
    int distinctAverages(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int N=nums.size(), start=0, end=N-1;

        set<double>s;
       while(start < end){
           int a=nums[start];
           start++;
           int b=nums[end];
           end--;
           double avg=(double)(a+b)/2;
           cout<<avg<<" ";
           s.insert(avg);
       }
       return s.size();
    }
};