class Solution {
public:
    double myPow(double x, int n) {
        if( x ==0 ) return 0;
        if (n ==0) return 1;
        double nn = x;
        bool flag= false;
        if(n<0) flag= true;
        n=abs(n);

        for( int i=0;i<n-1;i++) x*=nn;
        return (flag == true) ?1/x: x;
    }
};
