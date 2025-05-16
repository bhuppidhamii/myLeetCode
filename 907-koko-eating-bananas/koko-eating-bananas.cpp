class Solution {
public:
    bool canEatAllBananas(int x, vector<int>& piles, int h) {
        int time = 0;
        for (auto& p : piles) {
            time += p / x;
            if (p % x != 0) {
                time += 1;
            }
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(begin(piles), end(piles));
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAllBananas(mid, piles, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};