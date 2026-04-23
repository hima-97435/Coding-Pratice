class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int acx=0,acy=0;
        int n = heights.size();
        int ans = INT_MIN;
        for( int i=0;i<n;i++){
            for( int j=i+1;j<n;j++){
                int v1 = min(heights[i],heights[j])*(j-i);
                ans= max(ans,v1);
                
            }
        }
        return ans;
    }
};
