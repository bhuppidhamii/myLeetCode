class Solution {
  public:
    int maxArea(vector<int> &height) {
        // Jai Shri Ram
        int i=0;
        int j=height.size()-1;
        int maxArea = INT_MIN;
        while(i<=j){
            int l=height[i];
            int r=height[j];
            
            int area = min(l,r) * (j-i-1);
            if(area > maxArea) maxArea=area;
            
            if(l<=r){
                i++;
            }else{
                j--;
            }
        }
        
        return maxArea;
    }
};