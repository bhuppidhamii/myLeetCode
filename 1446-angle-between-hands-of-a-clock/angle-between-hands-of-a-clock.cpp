class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 1 min = 6 deg
        // 1 hr = 30 deg
        double mins = minutes;
        double minDeg = mins * 6;
        cout<<"min deg "<<minDeg;
        double hr = hour;
        if(hour == 12){
            hr = (double)(mins/60);
        }else{
            hr += (double)(mins/60);
        }
        double hrDeg = hr * 30;
        cout<<"hr deg "<<hrDeg;
        double ans = abs(minDeg-hrDeg);
        double total = 360;
        return min(ans, total-ans);
    }
};