class Solution {
public:
    bool check(vector<int>& citations, int mid){
        int count=0;
        for(auto &i:citations){
            if(i>= mid){
                count++;
            }
        }
        if(count >= mid) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int low = 1;
        int high = *max_element(citations.begin(), citations.end());
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(citations, mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};