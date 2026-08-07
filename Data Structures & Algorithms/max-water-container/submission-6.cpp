class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0, r = heights.size()-1;
        int lmax = heights[l], rmax=heights[r];
        int area =0;
        while(l<=r){
            lmax=max(lmax,heights[l]);
            rmax=max(rmax,heights[r]);

            area = max(area,(r-l)*min(lmax,rmax));
            if(heights[l]<heights[r]) {
                
                l++;
            }
            else {
                r--;
            }
        }
        return area;
    }
};
