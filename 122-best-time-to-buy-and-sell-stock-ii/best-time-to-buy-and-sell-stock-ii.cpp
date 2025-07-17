class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int maxP = 0, i = 0;
        while(i < N){
            int j = i+1;
            while(j < N && prices[j] > prices[j-1]){
                j++;
            }
            int profit = prices[j-1] - prices[i];
            maxP += profit;
            i = j;
        }
        return maxP;
    }
};