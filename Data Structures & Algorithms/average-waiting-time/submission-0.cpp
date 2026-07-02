class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time =0;
        long long ans =0;
        for(auto &c:  customers){
            int arrival = c[0];
            int cook = c[1];
            time = max(time, (long long) arrival);
            time+=cook;
            ans+=time-arrival;
        }
        return (double)ans/customers.size();

    }
};