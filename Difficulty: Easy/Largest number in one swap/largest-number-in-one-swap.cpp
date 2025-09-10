class Solution {
  public:
    string largestSwap(string &s) {
        // Jai Shri Ram ❤️
        
        // find the largest digit in string
        char largest='1';
        int idx = 0;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch >= largest){
                largest = ch;
                idx = i;
            }
        }
        
        // swap the largest digit with first digit 
        // which is not equal to the largest digit
        
        int idx2 = s.find_first_not_of(largest);
        
        if(idx2 == string::npos) return s; // all char are same eg- 111
        
        if(idx2 > idx) return s; // already lexicographically largest
        
        // swap
        swap(s[idx], s[idx2]);
        return s;
    }
};
