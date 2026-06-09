class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = 0, y =0;
        int n = cost.size();
        for( int i=n-1;i>=0;i--){
            int temp = cost[i]+min(x,y);
            y=x;
            x= temp;
            cout<<x<<" "<<y<<" "<< temp<<endl;
        }
        return min(x,y);
    }
};
