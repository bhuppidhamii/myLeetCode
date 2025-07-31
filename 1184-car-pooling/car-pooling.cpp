class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int N = 0;
        // find the maximum length of differnce array
        for(auto &t:trips){
            N = max(N, t[2]);
        }

        // create an difference array
        vector<int> diff(N + 3, 0);
        for (auto& t : trips) {
            int x = t[0];
            int s = t[1];
            int d = t[2];

            diff[s] += x;
            diff[d] -= x; // drop at d not d+1
        }

        // cummulative sum ------>
        int cumSum = diff[0];
        for (int i = 0; i <= N + 2; i++) {

            cumSum += diff[i];
            diff[i] = cumSum;
            if (diff[i] > capacity)
                return false;
        }
        return true;
    }
};