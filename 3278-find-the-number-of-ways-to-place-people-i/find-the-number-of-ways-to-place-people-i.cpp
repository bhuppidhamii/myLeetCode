class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int count =0;
        for(int i=0; i<n; i++){
            // A point
            int x1=points[i][0];
            int y1=points[i][1];

            // B point
            for(int j=0; j<n; j++){
                if(i==j) continue;

                int x2=points[j][0];
                int y2=points[j][1];

                // A is on the upper left side of B
                if(x1 <= x2 && y1 >= y2){

                    // check if C point is inside A & B rectangle
                    bool found=false;
                    for(int k=0; k<n; k++){
                        if(k==i || k==j) continue;

                        int x3=points[k][0];
                        int y3=points[k][1];

                        // condition for inside the rectangle
                        if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                            found=true;
                            break;
                        }
                    }
                    if(found == false){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};