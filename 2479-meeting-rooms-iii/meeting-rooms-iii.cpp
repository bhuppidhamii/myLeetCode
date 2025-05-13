class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> lastAvailAt(n, 0);   // track when each room becomes free
        vector<int> roomsUseCount(n, 0);       // usage count for each room

        for (const auto& meet : meetings) {
            int start = meet[0], end = meet[1];
            long long duration = end - start;

            int availableRoom = -1;
            for (int i = 0; i < n; ++i) {
                if (lastAvailAt[i] <= start) {
                    availableRoom = i;
                    break;
                }
            }

            if (availableRoom != -1) {
                // Assign to available room
                lastAvailAt[availableRoom] = end;
                roomsUseCount[availableRoom]++;
            } else {
                // No room is available at start, pick room that becomes free the earliest
                int earliestRoom = 0;
                for (int i = 1; i < n; ++i) {
                    if (lastAvailAt[i] < lastAvailAt[earliestRoom]) {
                        earliestRoom = i;
                    }
                }
                lastAvailAt[earliestRoom] += duration;
                roomsUseCount[earliestRoom]++;
            }
        }

        // Find room with max usage
        int mostUsedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomsUseCount[i] > roomsUseCount[mostUsedRoom]) {
                mostUsedRoom = i;
            }
        }
        return mostUsedRoom;
    }
};