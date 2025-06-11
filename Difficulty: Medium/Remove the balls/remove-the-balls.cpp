class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // Jai Shri Ram
        int N=color.size();
        stack<int>s1; // color
        stack<int>s2; // radius
        
        for(int i=0; i<N; i++){
            int c=color[i];
            int r=radius[i];
            
            if(s1.empty() && s2.empty()){ // if empty - push
                s1.push(c);
                s2.push(r);
            }else{ // if not empty
                if(s1.top() == c && s2.top() == r){ // check same
                    s1.pop();
                    s2.pop();
                }else{ // push it
                    s1.push(c);
                    s2.push(r);
                }
            }
        }
        return s1.size();
    }
};