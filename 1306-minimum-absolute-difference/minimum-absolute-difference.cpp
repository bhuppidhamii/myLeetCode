class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int N=arr.size();
        sort(arr.begin(), arr.end());
        int mini=INT_MAX;
        for(int i=0;i<N-1;i++){
            mini=min( mini, abs(arr[i]-arr[i+1]) );
        }
        vector<vector<int>> ans;
        for(int i=0;i<N-1;i++){
            if(abs(arr[i]-arr[i+1]) == mini){
                vector<int>temp={arr[i],arr[i+1]};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};