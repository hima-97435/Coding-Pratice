class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row= matrix.size(), col = matrix[0].size();
        vector<vector<int>> indegree(row,vector<int>(col,0));
        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        for( int r=0;r<row;r++){
            for(int c =0;c<col;c++){
                for(auto &d : directions){
                    int nr = r+d[0];
                    int nc = c+d[1];
                    if(nr>=0 && nc>=0 && nr<row && nc<col && matrix[r][c]<matrix[nr][nc]) indegree[nr][nc]++;
                }
            }
        }
        queue<pair<int, int>> q;
        for( int r=0;r<row;r++){
            for( int c=0;c<col;c++){
                if(indegree[r][c] == 0 ) q.push({r,c});
            }
        }
        int cnt=0;
        while(!q.empty()){
            int size= q.size();
            cnt++;
            for( int i=0;i<size;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto &d: directions){
                    int nr = r+d[0];
                    int nc= c+d[1];
                    if(nr>=0 && nc>=0 && nr<row && nc<col && matrix[nr][nc]>matrix[r][c]) {
                        indegree[nr][nc]--;
                        if(indegree[nr][nc] == 0) q.push({nr,nc});
                    }
                }
            }
        }
        return cnt;
    }
};
