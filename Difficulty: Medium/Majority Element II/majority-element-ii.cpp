class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        // Jai Shri Ram
        int maj1, maj2;
        int count1=0, count2=0;
        int N = nums.size();
        
        // assumption
        for(auto &n:nums){
            if(maj1==n){
                count1++;
            }else if(maj2==n){
                count2++;
            }else if(count1==0){
                maj1=n;
                count1=1;
            }else if(count2==0){
                maj2=n;
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        
        // validation
        count1=count2=0;
        for(auto &i:nums){
            if(i==maj1) count1++;
            if(i==maj2) count2++;
        }
        
        int req=N/3;
        vector<int>ans;
        if(count1>req){
            ans.push_back(maj1);
        }
        if(count2>req){
            ans.push_back(maj2);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};