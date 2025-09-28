class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(begin(arr), end(arr));
        
        int n = arr.size(), max_peri = 0;
        for(int i=n-1; i>=2; i--){
            if(arr[i] < arr[i-1]+arr[i-2]){
                max_peri = max(max_peri, arr[i]+arr[i-1]+arr[i-2]);
            }
        }
        return max_peri;
    }
};