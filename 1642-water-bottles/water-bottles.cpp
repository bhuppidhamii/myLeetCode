class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottlesICanDrink = numBottles;
        int res = totalBottlesICanDrink;
        while (totalBottlesICanDrink / numExchange > 0) {
            int fullBottles = totalBottlesICanDrink / numExchange;
            res += fullBottles;

            int rem = totalBottlesICanDrink % numExchange;

            totalBottlesICanDrink = fullBottles + rem;
        }
        return res;
    }
};