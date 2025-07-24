class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        for(auto &l:left){
            int dist = (l-0);
            maxi = max(maxi, dist);
        }
        for(auto &r:right){
            int dist = (n-r);
            maxi = max(maxi, dist);
        }
        return maxi;
    }
};