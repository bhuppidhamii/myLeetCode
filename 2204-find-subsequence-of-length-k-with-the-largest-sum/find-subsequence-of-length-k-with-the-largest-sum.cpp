class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int N=nums.size();
        for(int i=0;i<N;i++){
            pq.push(make_pair(nums[i],i));
        }

        vector<pair<int,int>> v;
        for(int i=0;i<k;i++){
            int data=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            v.push_back(make_pair(index,data));
        }
        sort(v.begin(),v.end());

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};