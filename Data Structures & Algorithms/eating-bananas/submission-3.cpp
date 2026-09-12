class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l<=r){
            int m = (l+r)>>1;
            long long hr = 0;
            for(int x: piles) {
                hr+=(x+m-1)/m;
            }
            if(hr<=h){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
