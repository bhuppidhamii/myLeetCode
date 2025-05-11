//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int N=arr.size();
        vector<int>v;
        for(int i=0; i<N; i++){
            int start = i;
            for(int j=i; j<N; j++){
                int end = j;
                int sum=0;
                for(int k=start; k<=end; k++){
                    sum+=arr[k];
                }
                v.push_back(sum);
            }
        }
        sort(begin(v), end(v));
        for(auto &i:v){
            // cout<<i<<"-";
        }
        // cout<<"\n";
        int n=v.size();
        int ans=v[n-k];
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends