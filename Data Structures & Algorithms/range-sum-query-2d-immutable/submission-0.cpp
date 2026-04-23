class NumMatrix {
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix= matrix;    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1=0;
        for( int i = row1;i<=row2;i++){
                for( int j = col1;j<=col2;j++){
                    s1+=matrix[i][j];
                }
        }
        return s1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */