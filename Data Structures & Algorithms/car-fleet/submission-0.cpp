class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int , int>> pp;
        for(int i=0;i<n;i++){
            pp.push_back({position[i],speed[i]});
        }
        sort(pp.rbegin(),pp.rend());
        int fleet =1;
        
        double prevtime = (double) (target - pp[0].first)/pp[0].second;
        for( int i=1;i<n;i++){
            double curr = ( double )(target - pp[i].first)/pp[i].second;
            if(curr> prevtime) {
                fleet++;
                prevtime=curr;
            }
        }
        return fleet;
    }
};
