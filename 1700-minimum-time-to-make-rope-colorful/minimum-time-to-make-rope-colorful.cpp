class Solution {
public:
    int solve(int i, int j, string &colors, vector<int>& neededTime){
        priority_queue<int, vector<int>, greater<int>> pq; // min heap;

        while(i<=j){
            pq.push(neededTime[i]);
            i++;
        }
        int ans = 0;
        while(pq.size() > 1){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
    int minCost(string &colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int i = 0;
        while(i < n){
            int j=i+1;
            while(j<n && colors[j] == colors[j-1]){
                j++;
            }
            if(i != j-1){
                ans += solve(i, j-1, colors, neededTime);
            }
            i=j;
        }
        return ans;
    }
};