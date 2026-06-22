class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int , int> mp;
        for(const auto& t : intervals){
            mp[t[0]]++;
            mp[t[1]]--;
        }
        vector<vector<int>> res;
        vector<int> interval;
        int have =0;
        for(const auto & [i , count]: mp){
            if(interval.empty()) {
                interval.push_back(i);
            }
            have+=count;
            if(have  == 0) {
                interval.push_back(i);
                res.push_back(interval);
                interval.clear();
            }
        }        
        return res;
    }
};
