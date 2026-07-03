class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size(),c =matrix[0].size();
        if( r == c){
            for(int i=0;i<r;i++){
                for(int j=0;j<i;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            
            return matrix;
        }
        vector<vector<int>> res(c,vector<int>(r));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
};