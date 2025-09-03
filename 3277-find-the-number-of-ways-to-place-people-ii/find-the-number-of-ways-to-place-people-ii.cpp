class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](auto &a, auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int n = points.size(), count = 0;

        for(int i=0; i<n; i++){

            // A point
            int x1 = points[i][0];
            int y1 = points[i][1];

            int max_y = INT_MIN;
            for(int j=i+1; j<n; j++){

                // B point
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue; // B A se uppr chala gya

                if( y2 > max_y){
                    count++;
                    max_y = y2;
                }
            }
        }
        return count;
    }
};