class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemainSum=0;

        long long minimizedR2Sum=LONG_LONG_MAX;

        for(int r1Col=0;r1Col<grid[0].size();r1Col++){
            firstRowRemainSum-=grid[0][r1Col];

            long long bestOfR2Sum=max(firstRowRemainSum,secondRowRemainSum);

            minimizedR2Sum = min(minimizedR2Sum, bestOfR2Sum);

            secondRowRemainSum+=grid[1][r1Col];
        }

        return minimizedR2Sum;
    }
};