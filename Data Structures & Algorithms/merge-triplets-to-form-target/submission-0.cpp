class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool findx = false;
        bool findy = false;
        bool findz = false;
        for(auto &t: triplets){
            int a = t[0];
            int b = t[1];
            int c = t[2];
            if(a>target[0] || b > target[1] || c>target[2]) continue;
            if(a == target[0] ) findx = true;
            if(b == target[1] ) findy = true;
            if(c == target[2] ) findz = true;
            if(findx && findy&& findz) return true;
        }
        return findx&&findy&&findz;
    }
};
