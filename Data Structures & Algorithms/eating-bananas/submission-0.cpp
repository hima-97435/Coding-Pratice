class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int l = 1;
       int r = *max_element(piles.begin(), piles.end());

       while(l<=r){
        long long m = l+(r-l)/2;
        int compute =0;
        for( int x: piles){
            if(compute > h ) break;
            compute+=(x+m-1)/m;

        }

        if(compute > h) l = m+1;
        else r = m-1;
       } 
    return l ;
    }
    
};
