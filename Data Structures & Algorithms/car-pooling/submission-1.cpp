class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
          sort(trips.begin(),trips.end() ,[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
             });
          priority_queue<pair<int, int>, vector<pair<int, int>> , greater<>> minheap;
          int curpass=0;
          for(const auto& trip: trips){
            int numpass = trip[0], start =trip[1], end = trip[2];
            while(!minheap.empty() && minheap.top().first<=start) {
                curpass-=minheap.top().second;
                minheap.pop();
            }
            curpass+=numpass;
            if(curpass>capacity) return false;
            minheap.emplace(end,numpass);
          }
          return true;
        
    }
};