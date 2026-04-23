class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return{};
        sort( intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        // int i=0;
        res.push_back(intervals[0]);
        for( int i=1;i<n;i++){
           vector<int> & addedlast=res.back();
           vector<int> & current = intervals[i];
           if(current[0]<=addedlast[1]){
            addedlast[1]=max(addedlast[1],current[1]);
           }
           else {
            res.push_back(current);
           }

        }
        return res;
    }
};
