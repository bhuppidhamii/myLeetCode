class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalWaitTime = 0;
        int currTime = 0;
        for (int i = 0; i < n; i++) {
            int arrivalTime = customers[i][0];
            int cookTime = customers[i][1];

            if (currTime < arrivalTime) {
                currTime = arrivalTime;
            }

            int waitTime = (currTime + cookTime) - arrivalTime;

            totalWaitTime += waitTime;

            currTime += cookTime;
        }
        return totalWaitTime / n;
    }
};