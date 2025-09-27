class Solution {
public:
    double findLength(vector<int>&a, vector<int>&b){
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];

        double len = double(sqrt(pow((x2-x1), 2) + pow((y2-y1), 2)));
        return len;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double max_area = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    vector<int> a = points[i];
                    vector<int> b = points[j];
                    vector<int> c = points[k];

                    double ab = findLength(a,b);
                    double bc = findLength(b,c);
                    double ca = findLength(c,a);

                    // area with 3 side
                    double s = (ab+bc+ca)/2;

                    double A = double(sqrt(s*(s-ab)*(s-bc)*(s-ca)));
                    if(A > max_area){
                        max_area = A;
                    }
                }
            }
        }
        return max_area;
    }
};