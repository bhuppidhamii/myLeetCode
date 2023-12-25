class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>arr;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto i:nums){
            pq.push(i);
        }

        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            arr.push_back(b);
            arr.push_back(a);
        }
        return arr;
    }
};