class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // Jai Shri Ram
        
        if(type == 1){
            // rotate clockwise
            while(k--){
                int back = dq.back();
                dq.pop_back();
                
                // push in front
                dq.push_front(back);
            }
        }else{
            // rotate anti-clockwise
            while(k--){
                int front = dq.front();
                dq.pop_front();
                
                // push in back
                dq.push_back(front);
            }
        } 
    }
};