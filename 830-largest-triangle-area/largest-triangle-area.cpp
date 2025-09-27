class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double max_area = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    vector<int> a = points[i];
                    vector<int> b = points[j];
                    vector<int> c = points[k];

                    int x1 = a[0], y1 = a[1];
                    int x2 = b[0], y2 = b[1];
                    int x3 = c[0], y3 = c[1];

                    // shoelace formula
                    double A = 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                    if(A > max_area){
                        max_area = A;
                    }
                }
            }
        }
        return max_area;
    }
};