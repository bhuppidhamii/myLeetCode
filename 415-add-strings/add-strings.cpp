class Solution {
public:
    bool checkAllZeros(string &str){
        bool zeros=true;
        for(auto &ch:str){
            if(ch != '0'){
                return false;
            }
        }
        return true;
    }
    string addStrings(string str1, string str2) {
        int N1=str1.size();
        int N2=str2.size();

        int i=N1-1, j=N2-1, carry=0;

        string result="";
        while(i>=0 || j>=0 || carry){
            int num1=0, num2=0;
            if(i>=0){
                num1=str1[i]-'0';
                i--;
            }
            if(j>=0){
                num2=str2[j]-'0';
                j--;
            }
            int sum=num1+num2+carry;
            if(sum > 9){
                int rem=sum%10;
                result+=to_string(rem);
                carry=sum/10;
            }else{
                result+=to_string(sum);
                carry=0;
            }
        }
        reverse(result.begin(), result.end());
        if(checkAllZeros(result)){
            return "0";
        }
        int idx=result.find_first_not_of('0');
        if(idx == string::npos){
            return result;
        }
        return result.substr(idx);
    }
};