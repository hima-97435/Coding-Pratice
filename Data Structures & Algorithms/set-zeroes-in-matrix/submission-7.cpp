class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rowwise(m, false);
        vector<bool> colwise(n , false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0) {rowwise[i]=true; colwise[j]=true;}
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowwise[i] || colwise[j]) matrix[i][j]=0;
            }
        }
        
    }
};
