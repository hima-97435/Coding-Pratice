class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), cols = matrix[0].size();
        vector<bool> rowzero(r,false);
        vector<bool> colzero(cols, false);
        for( int i=0;i<r;i++){
            for( int j =0;j<cols;j++){
                if(matrix[i][j] == 0) {
                    rowzero[i]= true;
                    colzero[j]= true;
                }
            }
        }
        for( int i=0;i<r;i++){
            for( int j=0;j<cols;j++){
                if(rowzero[i] || colzero[j]) matrix[i][j]=0;
            }
        }
    }
};
