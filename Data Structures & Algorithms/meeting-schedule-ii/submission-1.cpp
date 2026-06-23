/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        vector<int> startime;
        vector<int> endtime;
        for(int i=0;i<intervals.size();i++){
            startime.push_back(intervals[i].start);
            endtime.push_back(intervals[i].end);
        }
        sort(startime.begin(), startime.end());
        sort(endtime.begin(),endtime.end());
        int st=0;
        int en =0;
        int maxroom =0;
        int curoom=0;
        while(st<intervals.size()){
            if(startime[st]<endtime[en]){
                st++;
                curoom++;
            }
            else {
                curoom--;
                en++;
            }
            maxroom=max(maxroom,curoom);
        }
        return maxroom;
    }
};
