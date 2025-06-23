class Solution {
  public:
    string minSum(vector<int> &arr) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        
        string str1="";
        string str2="";
        
        int N=arr.size();
        
        for(int i=0; i<N; i++){
            if(i%2 == 0){
                str1+=to_string(arr[i]);
            }else{
                str2+=to_string(arr[i]);
            }
        }
        
        string ans = addStrings(str1, str2);
        int idx=ans.find_first_not_of('0');
        if(idx!=string::npos){
            ans=ans.substr(idx);
        }
        return ans;
    }
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = num1.length()-1, j = num2.length()-1;
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += num1[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            result += (sum % 10 + '0');
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};