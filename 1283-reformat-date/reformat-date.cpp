class Solution {
public:
    string reformatDate(string date) {
        string year="";
        int n=4;
        while(n--){
            year=date.back()+year;
            date.pop_back();
        }
        date.pop_back();
        // cout<<year<<" - "<<date.size();
        // cout<<date<<endl;
        string month="";
        n=3;
        while(n--){
            month=date.back()+month;
            date.pop_back();
        }
        date.pop_back();
        map<string,string>m;
        m.insert({"Jan","01"});
        m.insert({"Feb","02"});
        m.insert({"Mar","03"});
        m.insert({"Apr","04"});
        m.insert({"May","05"});
        m.insert({"Jun","06"});
        m.insert({"Jul","07"});
        m.insert({"Aug","08"});
        m.insert({"Sep","09"});
        m.insert({"Oct","10"});
        m.insert({"Nov","11"});
        m.insert({"Dec","12"});
        month=m[month];
        // cout<<date.size();
        string d="";
        n=2;
        while(n--){
            date.pop_back();
        }
        d=date;
        if(d.size()==1){
            d="0"+d;
        }
        // cout<<year<<"-"<<month<<"-"<<d;
        return year+"-"+month+"-"+d;
    }
};
