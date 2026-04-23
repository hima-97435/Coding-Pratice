class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l =*max_element(weights.begin(),weights.end());
        int r =accumulate(weights.begin(),weights.end(),0);
        while(l<=r){
            int m = l+ (r-l)/2;
            int hour = 1;
            int curr_weight=0;
            for( int x: weights){
                if(curr_weight+x > m) {
                    hour++;
                    curr_weight=x;
                }
                else curr_weight+=x;

            }
            if(hour>days) l=m+1;
            else r = m-1;
        }
        return l;
    }
};