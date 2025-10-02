class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int totalEmptyBottles = numBottles;

        while(totalEmptyBottles >= numExchange){
            totalEmptyBottles -= numExchange;
            totalEmptyBottles += 1;
            total += 1;

            numExchange += 1;
        }
        return total;
    }
};