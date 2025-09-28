class Solution {
  public:
    #define P pair<int,int>
    vector<int> longestSubarray(vector<int>& nums, int limit) {
        // Jai Shri Ram
        
        priority_queue<P>maxHeap; // to store max ele, idx
        priority_queue<P, vector<P>, greater<P> >minHeap; // to store min ele, idx
        
        int j = 0, n = nums.size();
        int i=0;
        int idx1=0, idx2=0;
        int max_len = 0;
        while(j < n){
            
            maxHeap.push({nums[j], j});
            
            minHeap.push({nums[j], j});
            
            if(minHeap.size()>0 && maxHeap.size()>0 && maxHeap.top().first-minHeap.top().first <= limit){
                // max_len = max(max_len, j-i+1);
                if(j-i+1> max_len){
                    max_len = j-i+1;
                    idx1=i;
                    idx2=j;
                }
            }

            while(minHeap.size()>0 && maxHeap.size()>0 && maxHeap.top().first - minHeap.top().first > limit){
                i = min(minHeap.top().second, maxHeap.top().second)+1;

                // remove from min-heap
                while(minHeap.size()>0 && minHeap.top().second < i){
                    minHeap.pop();
                }

                // remove from max-heap
                while(maxHeap.size()>0 && maxHeap.top().second < i){
                    maxHeap.pop();
                }
            }
            j++;
        }
        vector<int>ans;
        while(idx1<=idx2){
            ans.push_back(nums[idx1]);
            idx1++;
        }
        return ans;
    }
};