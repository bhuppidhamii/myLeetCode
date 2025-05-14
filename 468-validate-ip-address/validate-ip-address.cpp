class Solution {
public:
    bool validateIPv4(string& s) {
        int N = s.size();
        int i = 0, count = 0;
        if(s[N-1] == '.') return false;
        while (i < N) {
            string temp = "";
            char ch = s[i];
            if(isdigit(ch) == false) return false;
            temp += ch;
            if (ch == '.')
                return false;
            int j = i + 1;
            while (j < N && s[j] != '.') {
                if(isdigit(s[j]) == false) return false;
                temp += s[j];
                j++;
            }
            cout << temp << ".";
            if (temp.size() == 0 || temp.size() > 3)
                return false;
            cout<<"1"; 
            if (temp.size() != 1 && temp[0] == '0')
                return false;
            cout<<"2";
            int num = stoi(temp);
            if (num < 0 || num > 255)
                return false;
            count++;
            j++;
            i = j;
        }
        return count == 4;
    }
    bool validateIPv6(string& s) {
        int N = s.size();
        int i = 0, count = 0;
        if(s[N-1]==':') return false;
        while (i < N) {
            char ch = s[i];
            if(ch == ':') return false;
            string temp = "";
            temp+=ch;
            int j = i + 1;
            while (j < N && s[j] != ':') {
                temp += s[j];
                j++;
            }
            // cout<<temp<<":";
            count++;
            if (temp.size() < 1 || temp.size() > 4)
                return false;
            // cout<<"1";
            if (hexaUpperCheck(temp) == false)
                return false;
            // cout<<"2"<<"-";
            j++;
            i = j;
        }
        return count == 8;
    }
    bool hexaUpperCheck(string& s) {
        bool digit = false;
        bool lowercase = false;
        bool uppercase = false;

        for (auto& ch : s) {
            if (isdigit(ch)) {
                digit = true;
            } else if (islower(ch)) {
                if (ch > 'f')
                    return false;
                lowercase = true;
            } else if (isupper(ch)) {
                if (ch > 'F')
                    return false;
                uppercase = true;
            }
        }
        return digit || lowercase || uppercase;
    }
    string validIPAddress(string query) {
        if(query.size() == 0) return "Neither";
        if (validateIPv4(query)) {
            return "IPv4";
        }
        if (validateIPv6(query)) {
            return "IPv6";
        }
        return "Neither";
    }
};