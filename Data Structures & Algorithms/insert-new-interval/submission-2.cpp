class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       
       int n = intervals.size();
       int i=n;
       vector<vector<int>> res;
        int  l =0, r = n-1;
        while(l<=r) {
            int mid= l+(r-l)/2;
            if(intervals[mid][1]>=newInterval[0]) {i= mid; r = mid-1;}
            else {l = mid+1;}
        }
        for(int k=0;k<i;k++) res.push_back(intervals[k]);
       while(i<n && intervals[i][0]<=newInterval[1]) {newInterval[0]= min(newInterval[0], intervals[i][0]); newInterval[1]= max(newInterval[1], intervals[i][1]); cout<<i<<endl; i++; }
       res.push_back(newInterval);
       while(i<n){ res.push_back(intervals[i]); cout<<i<<endl; cout<<i<<endl; i++;} 
       return res;
    }
};
