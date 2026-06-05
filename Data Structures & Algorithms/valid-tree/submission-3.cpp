class Solution {
    int findroot( int i , vector<int> & parent){
        if(parent[i] == i) return i;
        return parent[i]= findroot(parent[i], parent);
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
     if(edges.size()!= n-1) return false;
     vector<int> Parent(n);
     for( int i=0;i<n;i++) Parent[i]=i;
     for(auto & e: edges){
        int rA = findroot(e[0], Parent);
        int rB = findroot(e[1], Parent);
        if(rA == rB) return false;
        Parent[rA]= rB;

     }
     return true;
    }
};
