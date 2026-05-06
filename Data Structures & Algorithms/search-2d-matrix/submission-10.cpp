class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int l =0, r = row*col-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int r1 = mid/col;
            int c1 = mid%col;
            
            if(matrix[r1][c1] == target) return true;
            else if(matrix[r1][c1]> target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
