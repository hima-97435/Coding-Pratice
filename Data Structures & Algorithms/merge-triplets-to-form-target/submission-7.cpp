class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> m = {0,0,0};
        int n = triplets.size();
        for(int i=0;i<n;i++){
            vector<int> current = triplets[i];
            if(current[0]>target[0] or current[1]>target[1] or current[2]>target[2] ) continue;
            m[0]=max(m[0],current[0]);
            m[1]=max(m[1],current[1]);
            m[2]=max(m[2],current[2]);
            
        }
        return m == target;
    }
};
