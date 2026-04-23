class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector<int> count(grid.size()*grid.size()+1,0);
        int a =-1, b=-1 ;
        for(auto & g : grid){
           for(int gi : g) count[gi]++;
        }
        for( int i=0;i<=grid.size()*grid.size();i++) {
            if(count[i] == 2) a=i;
            if(count[i] == 0) b=i;
        }
        return {a,b};

    }
};