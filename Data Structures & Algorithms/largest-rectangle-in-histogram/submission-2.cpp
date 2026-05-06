class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // [1,3,7]
        // if considering 1 as all same throught height then area becomes 1X3 = 3
        // for considering 3 for index 1 and 2 then area becomes 3X2= 6 
        // ouptut is 7 how?
        // picked last element
        // [7,1,7,2,2,4]
        // pick last 4 elements and there minimum then the output would 4X2 = 8 coorect output
        if( heights.size() == 0) return 0;
        int val = 0;
        for( int i=0;i<heights.size();i++){
            int vall = heights[i];
            int j = i+1;
            int k = i-1;
            while(j<heights.size() && vall<=heights[j]){
                j++;
            }
            while(k>=0 && vall <= heights[k]) k--;
            int ans = (j-k-1)*vall;
            val=max(val,ans);

        }
        return val;
    }
};
