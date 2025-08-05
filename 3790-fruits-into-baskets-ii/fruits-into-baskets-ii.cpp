class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = fruits.size();
        int count = 0;
        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                if (baskets[j] != -1 && fruits[i] != -1 && baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    fruits[i] = -1;
                    count++;
                    break;
                }
            }
        }
        return N-count;
    }
};