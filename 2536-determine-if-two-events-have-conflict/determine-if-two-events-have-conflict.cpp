class Solution {
private:
    int timeConverter(string s){
        // HH:MM
        int hours = stoi(s.substr(0, 2));
        int minutes = stoi(s.substr(3, 2));

        return hours * 60 + minutes; // Convert time to minutes
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int ev1ST = timeConverter(event1[0]);
        int ev1ET = timeConverter(event1[1]);

        int ev2ST = timeConverter(event2[0]);
        int ev2ET = timeConverter(event2[1]);

        // // Check if the time ranges overlap in any way
        // if ((ev1ST <= ev2ST && ev2ST <= ev1ET) || 
        //     // event2 starts within event1
        //     (ev1ST <= ev2ET && ev2ET <= ev1ET) || 
        //     // event2 ends within event1
        //     (ev2ST <= ev1ST && ev1ST <= ev2ET) || 
        //     // event1 starts within event2
        //     (ev2ST <= ev1ET && ev1ET <= ev2ET))   
        //     // event1 ends within event2
        // {
        //     return true;
        // }

        // return false;
        return ev2ST<=ev1ET && ev1ST<=ev2ET;
    }
};