class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target ) return 0;
        unordered_map<int , vector<int>> mp;
        for(int bus =0 ; bus<routes.size();bus++){
            for(int stop: routes[bus]){
                mp[stop].push_back(bus);
            }
        }
        queue<int> q;
        unordered_set<int> visitedcnt;
        vector<bool> usedbus(routes.size(),false);
        int bus_Stop=0;
        q.push(source);
        visitedcnt.insert(source);
        while(!q.empty()){
            int sz = q.size();
            bus_Stop++;
            while(sz--){
                int stop = q.front();
                q.pop();
                
                for(int bus: mp[stop]){
                    if(usedbus[bus]) continue;
                    usedbus[bus]=true;
                    for(int nxtstop: routes[bus]){
                        if (nxtstop == target ) return bus_Stop;
                        if(!visitedcnt.count(nxtstop)) {
                            visitedcnt.insert(nxtstop);
                            q.push(nxtstop);
                        }
                    }
                }
            }
        }
        return -1;
    }
};