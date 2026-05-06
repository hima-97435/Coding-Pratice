#include<bits/stdc++.h>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1,hi=*max_element(piles.begin(), piles.end());
        int ans = hi;
        while(l<=hi){
             int m = l+(hi-l)/2;
             long long hour = 0;
             for( int pile: piles) hour+=(pile+m-1)/m;
            if(hour<=h){
                ans=m;
                hi=m-1;
            }
            else l=m+1;
        }
        return ans;

    }
};
