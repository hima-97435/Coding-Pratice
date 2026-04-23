class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // this gets add up to the last of cost array .
        int n = cost.size();
        for( int i=n-4;i>=0;i--){
            cost[i]=min(cost[i]+cost[i+1],cost[i]+cost[i+2]);

        }
        return min(cost[0],cost[1]);

    }
};
