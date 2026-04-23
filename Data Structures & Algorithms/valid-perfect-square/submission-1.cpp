class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l =1, r = num;
        while(l<=r){
            long long mid = l +(r-l)/2;
            long long val = mid*mid;
            if( val == num) return true;
            else if(val > num) r = mid-1;
            else l = mid+1;

        }
        return false;
    }
};