class Solution {
public:
   
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>> pq;
        for( auto & p : points){
            int x = p[0], y=p[1];
            int  val = (pow(x,2)+pow(y,2));
            pq.push({val, p});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> res ;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
