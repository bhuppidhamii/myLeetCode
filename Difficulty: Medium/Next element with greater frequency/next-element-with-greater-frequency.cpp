class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;
    
        for (auto it : arr) {
            freq[it]++;
        }
    
        vector<int> res(n, -1);    
        stack<int> s;              
    
        for (int i = 0; i < n; i++) {
            
            // While current frequency is 
            // greater than frequency at stack top
            while (!s.empty() && freq[arr[i]] > freq[arr[s.top()]]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    
        return res;
    }
};
