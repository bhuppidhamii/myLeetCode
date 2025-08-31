class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // Jai Shri Ram
        int N = arr.size();
        int i = 0, j= N-1;
        int max_area = 0;
        while(i < j){
            int length = min(arr[i], arr[j]);
            int breadth = j-i;
            int area = length * breadth;
            max_area = max(area, max_area);
            
            if(arr[i] <= arr[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_area;
    }
};