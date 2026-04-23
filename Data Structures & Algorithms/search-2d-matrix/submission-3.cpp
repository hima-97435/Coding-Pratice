class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int index = -1;
        for( int i=0;i<row;i++){
            if(matrix[i][0] <= target && matrix[i][col-1] >= target ) {
                index  =i;
                break;
            }
        }
        if( index == -1 ) return false;
        int l =0, r = matrix[0].size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(matrix[index][mid] == target) return true;
            else if(matrix[index][mid] > target) r = mid-1;
            else l = mid+1;
        } 
        return false;
    }
};
