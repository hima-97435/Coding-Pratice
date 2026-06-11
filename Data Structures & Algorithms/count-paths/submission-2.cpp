class Solution {
public:
    int uniquePaths(int m, int n) {
        int toal =m+n-2;
        int k = min(m-1, n-1);
        long long path =1;
        for( int i=1;i<=k;i++){
            path=path*(toal-k+i)/i;
        }
        return (int)path;
    }
};
