class Solution {
public:
vector<vector<int>> intervals;
vector<int> cache;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        intervals.resize(n, vector<int>(3));
        cache.assign(n, -1);
        for(int i=0;i<n;i++){
            intervals[i]={startTime[i], endTime[i], profit[i]};
        }        
        sort(intervals.begin(), intervals.end());
        auto dfs =[&] (auto&&self, int i) -> int{
            if( i == n) return 0;
            if(cache[i] != -1) return cache[i];
            int res = self(self,i+1);
            int j=i+1;
            while(j<n && intervals[i][1]>intervals[j][0]) j++;
            return cache[i]=max(res,intervals[i][2]+self(self,j));
        };
        return dfs(dfs,0);
    }
};