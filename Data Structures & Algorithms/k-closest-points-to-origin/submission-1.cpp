class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l =0 , r = points.size()-1;
        int pivot = points.size();
        while(pivot!=k){
            pivot= parition(points , l ,r);
            if(pivot<k) l = pivot+1;
            else r= pivot-1;
        }
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
    int parition(vector<vector<int>>& points, int l , int r){
        int pivotindex = r;
        int pivotdistance = euclidean(points[pivotindex]);
        int i=l;
        for( int j=l;j<r;j++){
            if(euclidean(points[j]) <= pivotdistance){
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }
    int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};
