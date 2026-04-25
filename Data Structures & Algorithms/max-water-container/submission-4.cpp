class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0 , r = heights.size()-1;
        int area =0;
        
        while(l<r){
            int wd = r-l;
            int heig = min(heights[r],heights[l]);
            int cur_area= wd*heig;
            area=max(area, cur_area);
            if(heights[l]<heights[r]) {
                l++;
            }
            else r--;
        }
        return area;
    }
};
