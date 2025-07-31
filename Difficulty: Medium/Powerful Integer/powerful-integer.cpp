class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // Jai Shri Ram
        
        // difference array technique
        int max_ele = -1;
        for(auto &i:intervals){
            for(auto &n:i){
                max_ele=max(max_ele, n);
            }
        }
        // cout<<max_ele;
        
        // create difference array
        vector<int>diff(max_ele+2, 0);
        
        // fill the difference array
        int x = 1;
        for(auto &i:intervals){
            int a = i[0];
            int b = i[1];
            
            diff[a] += x;
            diff[b+1] -= x;
        }
        
        // run commulative sum
        int cumSum = diff[0];
        for(int i = 1; i <= max_ele+1; i++){
            // cout<<diff[i]<<" ";
            cumSum += diff[i];
            diff[i] = cumSum;
            // cout<<diff[i]<<" ";
        }
        
        int powerful_ele = -1;
        for(int i=1; i<= max_ele+1; i++){
            if(diff[i] >= k){ // at least k times
                powerful_ele = max(powerful_ele, i);
            }
        }
        
        return powerful_ele;
    }
};