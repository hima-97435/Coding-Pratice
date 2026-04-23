class UnionFind{
    vector<int> parent;
    vector<double> weight;

    public:
    UnionFind( int n){
        parent.resize(n);
        weight.assign(n,1.0);
        for( int i=0;i<n;i++) parent[i]=i;
    }
    int find( int x){
        if(x!=parent[x]) {
            int og = parent[x];
            parent[x]=find(parent[x]);
            weight[x]*=weight[og];
        }
        return parent[x];
    }
    void unionsets( int x, int y , double value){
        int rx = find(x), ry = find(y);
        if(rx != ry){
            parent[rx] = ry;
            weight[rx] = value*weight[y]/weight[x];
        }
    }
    double getratio( int x, int y){
        if(find(x) != find(y) ) return -1.0;
        return weight[x]/weight[y];
    }
    
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
    vector<double>& values, vector<vector<string>>& queries) {
       // question is simple , that we need to compute ci/di simply
       // and if it not double ( not divisble) then answer -1.0
       // but what about  
       // equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"]]
        unordered_map<string , int> id;
        int idx =0;
        for(auto & e : equations){
            if(!id.count(e[0])) id[e[0]] = idx++;
            if(!id.count(e[1])) id[e[1]] = idx++;
        }
        UnionFind uf(idx);
        for( int i=0;i<equations.size();i++){
            int a = id[equations[i][0]];
            int b = id[equations[i][1]];
            uf.unionsets(a,b, values[i]);
        }
        vector<double> result;
        for(auto & q: queries){
            if(!id.count(q[0]) || !id.count(q[1])) {
                result.push_back(-1.0);
                continue;
            }
            int a = id[q[0]];
            int b = id[q[1]];

            result.push_back(uf.getratio(a,b));
        }
        return result;
    }
};