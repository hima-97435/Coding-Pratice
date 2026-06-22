class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxval = 0;

        for(const auto & t: intervals){
            maxval = max(maxval,t[0]);
        }
        vector<int> mp(maxval+1,0);
        for(const auto &p: intervals){
            mp[p[0]]=max(p[1]+1,mp[p[0]]);
        }
        vector<vector<int>> res;
        int have =-1;
        int intervalstart =-1;
        for( int i=0;i<mp.size();i++){
            if(mp[i]!=0){
                if(intervalstart == -1) intervalstart=i;
                have = max(have, mp[i]-1); 
            }
            if(have == i){
                res.push_back({intervalstart, have});
                have =-1;
                intervalstart=-1;
            } 
        }
        if(intervalstart != -1) res.push_back({intervalstart, have});
        return res;
    }
};
