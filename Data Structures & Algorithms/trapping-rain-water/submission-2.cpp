class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l =0 , r = n-1, l_max =0 , r_max=0;
        int toal=0;
        while(l<r){
            if(height[l]<height[r]){
                l_max = max(l_max, height[l]);
                toal+=l_max-height[l];
                l++;
            }
            else {
                r_max=max(r_max, height[r]);
                toal+=r_max-height[r];
                r--;
            }
        }
        return toal;

    }
   
};
