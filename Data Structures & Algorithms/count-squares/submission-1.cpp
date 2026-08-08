class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> ptscount;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptscount[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res =0;
        int x1 = point[0], y1 = point[1];
        for(auto&[y2,cnt]: ptscount[x1])
        {
            int side = y2-y1;
            if(side == 0 ) continue;
            int x3 = x1+side ,x4=x1-side;
            res+=cnt*ptscount[x3][y1]*ptscount[x3][y2];
            res+=cnt*ptscount[x4][y1]*ptscount[x4][y2];
        }
        return res;
    }
};
