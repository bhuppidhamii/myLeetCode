class Solution {
  public:
  
    vector<int> leftSmaller(vector<int>& arr){
        
        int n = arr.size();
        
        vector<int> left(n,-1);
        
        stack<int> s;
        s.push(0);
        
        
        
        for(int i=1;i<n;i++){
            
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            
            if(!s.empty()){
                left[i]=s.top();
            }
            
            s.push(i);
        }
        
        return left;
        
    }
    
     vector<int> rightSmaller(vector<int>& arr){
        
        int n = arr.size();
        
        vector<int> right(n,n);
        
       
        
        stack<int> s;
        
        s.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            
            if(!s.empty()){
                right[i]=s.top();
            }
            
            s.push(i);
        }
        
        return right;
        
    }
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
         int n = arr.size();
        vector<int> left = leftSmaller(arr);
        vector<int> right  = rightSmaller(arr);
        
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            int windowSize = right[i]-left[i]-2;
            
          
            
            ans[windowSize] = max(ans[windowSize],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        
        return ans;
    }
};