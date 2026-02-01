class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // Jai Shri Ram
        int N = arr.size();
        map<int,int>mp; // ordered map
        for(int i=0; i<k-1; i++){
            mp[-arr[i]]++;
        }
        
        int i=0;
        vector<int>ans;
        for(int j=k-1; j<N; j++){
            mp[-arr[j]]++;
            
            // extract the max element in the window 
            auto firstIterator  = mp.begin();
            int maxEle = -(firstIterator->first);
            ans.push_back(maxEle);
            // cout<<maxEle<<" ";
            
            // remove the ith element 
            mp[-arr[i]]--;
            if(mp[-arr[i]]==0) mp.erase(-arr[i]);
            i++;
        }
        return ans;
    }
};