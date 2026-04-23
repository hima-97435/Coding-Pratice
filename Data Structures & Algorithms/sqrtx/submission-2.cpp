class Solution {
public:
    int mySqrt(int x) {
        int i=1, j = x;
        while(i<=j){
            long long mi = i+(j-i)/2;
            long long val = mi*mi;
            if(val == x) return mi;
            else if(val >x) j = mi-1;
            else i = mi+1;

        }
        return j;
    }
};