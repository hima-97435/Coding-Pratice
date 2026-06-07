class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalcost=0;
        int edgesconnected =0;
        vector<int> mindis(n,INT_MAX);
        vector<bool> vis(n, false);
        mindis[0]=0;
        while(edgesconnected<n){
            int curnode=-1;
            int curmin=INT_MAX;
            for( int i=0;i<n;i++){
                if(!vis[i] && curmin>mindis[i]){
                    curmin=mindis[i];
                    curnode=i;
                }
            }
            totalcost += curmin;
            vis[curnode]= true;
            edgesconnected++;
            for( int nextnode =0;nextnode<n;nextnode++){
                if(!vis[nextnode]){
                    int distance = abs(points[curnode][0]- points[nextnode][0]) + abs(points[curnode][1]- points[nextnode][1]);
                    if(distance<mindis[nextnode]){
                        mindis[nextnode]= distance;
                    }
                }
            }
        }
        return totalcost;
    }
};
