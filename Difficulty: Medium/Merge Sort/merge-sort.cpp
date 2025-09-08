class Solution {
  public:
    void merge(vector<int>& arr, int l, int m, int r){
        // determine the size of L & R arrays
        int n1 = m-l+1;
        int n2 = r-m+1-1;
        
        // create L & R arrays
        vector<int>L(n1, 0);
        vector<int>R(n2, 0);
        int k = l;
        
        // fill the L & R arrays
        for(int i=0; i<n1; i++){
            L[i] = arr[k];
            k++;
        }
        for(int i=0; i<n2; i++){
            R[i] = arr[k];
            k++;
        }
        
        // now merge L & R in arr
        int i = 0; // L
        int j = 0; // R
        k = l; // arr
        
        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++, k++;
            }else{
                arr[k] = R[j];
                j++, k++;
            }
        }
        
        // remaining elements
        while(i<n1){
            arr[k] = L[i];
            i++, k++;
        }
        
        while(j<n2){
            arr[k] = R[j];
            j++, k++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // Jai Shri Ram
        if(l >= r){
            return;
        }
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid); // sort krke lana
        mergeSort(arr, mid+1, r); // sort krke lana
        merge(arr, l, mid, r); // mai merge kar dunga
    }
};