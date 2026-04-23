class Solution {
public:
    int trap(vector<int>& height) {
       int total_water=0;
       int n = height.size();
        // vector<int> left(n,0),right(n,0);
        // left[0]=height[0];
        int l =0, r=n-1, l_max =0,r_max=0;
        // for( int i=1;i<n;i++){
        //     left[i]=max(height[i],left[i-1]);
        // }
        // right[n-1]=height[n-1];
        // for( int i=n-2;i>=0;i--){
        //     right[i]=max(height[i],right[i+1]);
        // }

      while(l<r){
        if(height[l]<height[r]){
            l_max=max(l_max,height[l]);
            total_water+=l_max-height[l];
            l++;
        }
        else {
            r_max = max(r_max, height[r]);
            total_water+=r_max-height[r];
            r--;

        }
      }
       return total_water;
    }
};
