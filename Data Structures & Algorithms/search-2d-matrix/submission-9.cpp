class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        for( int i=0;i<row;i++){
            if(target>=matrix[i][0] && target<=matrix[i][col-1]){
                int low =0;
                int high = col-1;
                while(low<=high){
                    int m = low+(high-low)/2;
                    if(matrix[i][m] == target ) return true;
                    else if(matrix[i][m] > target) high=m-1;
                    else low=m+1;
                }
                return false;
            }
        }
        return false;
    }
};
