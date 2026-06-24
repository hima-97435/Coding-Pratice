class CountSquares {
private:
    unordered_map<long , int> ptscount;
    vector<vector<int>> pts;
    long getkey(int x, int y){
        return (static_cast<long>(x) << 32) | static_cast<long> (y);
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getkey(point[0], point[1]);
        ptscount[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];
        for(const auto& pt: pts){
            int x = pt[0], y= pt[1];
            if(abs(py-y) != abs(px-x) || x== px || y== py) continue;
            res+=ptscount[getkey(x,py)] *ptscount[getkey(px,y)]; 
        }
        return res;
    }
};
