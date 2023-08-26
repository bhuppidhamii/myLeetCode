class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int count=0, currSum=0;

        for(int i=0; i<k; i++){
            currSum+=arr[i];
        }

        if(currSum/k >= threshold){
            count++;
        }

        for(int i=k; i<n; i++){
            int addIndex = i;
            int removeIndex = i-k;

            currSum += arr[addIndex];
            currSum -= arr[removeIndex];

            if(currSum/k >= threshold){
                count++;
            }
        }
        return count;
    }
};