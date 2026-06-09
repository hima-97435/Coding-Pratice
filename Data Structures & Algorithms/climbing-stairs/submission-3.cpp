class Solution {
public:
    int climbStairs(int n) {
        int x = 1;
        int y = 1;
        for( int i=2;i<=n;i++){
            int temp = x+y;
            x=y;
            y=temp;
        }
        return y;
    }
};
