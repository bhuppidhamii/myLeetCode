class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Jai Shri Ram
        
        int N = arr.size();
        
        vector<int>t(N, 1);    // lis ending at i index
        vector<int>prev(N, -1); // vector to store prev index in lis
        int maxLISlength = -1; // to store max-lis length
        int maxLISIdx = -1;    // to store max-lis element index
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]){
                    if(t[j] + 1 > t[i]){ // update the t array
                        t[i] = t[j] + 1;
                        
                        // store the previous element index of t[i]
                        prev[i] = j;
                        
                        if(t[i] > maxLISlength){
                            maxLISlength = t[i];
                            maxLISIdx = i;
                        }
                    }
                }
            }
        }
        
        vector<int>res;
        int idx = maxLISIdx;
        // cout<<idx<<"\n";
        if(idx == -1){ // if no lis > 1 is found
            return {arr[0]};
        }
        while(idx != -1){
            res.push_back(arr[idx]);
            idx = prev[idx];
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};