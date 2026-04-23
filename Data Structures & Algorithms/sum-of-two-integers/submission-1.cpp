class Solution {
public:
    int getSum(int a, int b) {
        while( b != 0 ){
            int cr = (a&b)<<1;
            a^=b;
            b=cr;
        }
        return a;
    }
};
