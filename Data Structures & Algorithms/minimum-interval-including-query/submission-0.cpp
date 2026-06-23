class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<pair<int , int>> sq;
        for( int i=0;i<m;i++){
            sq.push_back({queries[i],i});
        }
        sort(sq.begin(),sq.end());
        sort(intervals.begin(), intervals.end());
        vector<int> result (m , -1);
        int i=0;
        priority_queue<
        pair<int , int> , 
        vector<pair<int, int>> ,
        greater<pair<int, int>>
        > pq;
        for(const auto [ queyval , index] : sq){
            while(i<n && intervals[i][0]<=queyval){
                int len = intervals[i][1]-intervals[i][0]+1;
                pq.push({len,intervals[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().second<queyval) pq.pop();
            if(!pq.empty()){
                result[index]=pq.top().first;
            }
        }
        return result;
    }
};
