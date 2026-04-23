class Solution {
public:
    int climbStairs(int n) {
        int ans=0;
        int x1=1,x2=1;

        for( int i=n-2;i>=0;i--){
            int temp=x1;
            x1=x1+x2;
            x2=temp;
        }
        return x1;
    }
};
