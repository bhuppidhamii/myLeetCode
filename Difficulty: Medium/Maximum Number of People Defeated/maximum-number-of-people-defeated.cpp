class Solution {
  public:
    int binarySearch(vector<int>&prefixSum, int p){
        int low = 0;
        int high = prefixSum.size()-1;
        int ans=0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(prefixSum[mid]==p)return mid+1;
            
            if(prefixSum[mid] > p){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int maxPeopleDefeated(int p) {
        // Jai Shri Ram
        
        vector<int>prefixSum;
        int sum = 0;
        int i=1;
        while(sum <= p){
            sum+=(i*i);
            i++;
            prefixSum.push_back(sum);
        }
        
        // for(auto &p:prefixSum){
        //     cout<<p<<", ";
        // }
        // cout<<"\n";
        
        // use binary search to find index of element > p in prefixSum
        // if(element == p) in prefixSum return i+1;
        return binarySearch(prefixSum, p);
    }
};
