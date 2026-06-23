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
        sort(intervals.begin(), intervals.end(),[](auto &a, auto&b) {
            return a.start<b.start;
        }); 
        /* intervals =[[10,15],[1,5]] --> this the example by sorting is needed.*/
        priority_queue<int , vector<int> , greater<int>> pq;
        for( int i=0;i<intervals.size();i++){
            if(!pq.empty() && intervals[i].start>=pq.top() ) pq.pop();
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
