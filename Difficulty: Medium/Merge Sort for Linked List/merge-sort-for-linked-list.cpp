class Solution {
  public:
    void merge(vector<int>&arr, int l, int mid, int r){
        int n1 = mid-l+1;
        int n2 = r-mid+1-1;
        vector<int>L(n1, 0);
        vector<int>R(n2, 0);
        
        int k = l;
        // fill L & R arrays
        for(int i=0; i<n1; i++){
            L[i] = arr[k];
            k++;
        }
        for(int i=0; i<n2; i++){
            R[i] = arr[k];
            k++;
        }
        
        int i = 0;
        int j = 0;
        k = l;
        // merge into original array
        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++, k++;
            }else{
                arr[k] = R[j];
                j++, k++;
            }
        }
        
        while(i < n1){
            arr[k] = L[i];
            i++, k++;
        }
        
        while(j < n2){
            arr[k] = R[j];
            j++, k++;
        }
    }
    void mergeSort(vector<int>&arr, int l, int r){
        if(l >= r) return;
        
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    Node* mergeSort(Node* head) {
        // Jai Shri Ram
        
        vector<int>arr;
        Node *temp = head;
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        // merge-sort
        mergeSort(arr, 0, arr.size()-1);
        
        // dummy technique
        Node *dummy = new Node(0);
        temp = dummy;
        for(auto &i:arr){
            Node *newNode = new Node(i);
            temp->next= newNode;
            temp=temp->next;
        }
        
        return dummy->next;
    }
};