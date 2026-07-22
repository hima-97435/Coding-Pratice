class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prfx = strs[0];
        int n = strs.size();
        for(int i=1;i<n;i++){
            int j=0;
            while(j<min(prfx.size(), strs[i].size())) {
                if(prfx[j] != strs[i][j]) break;
                j++;
            } 
            prfx=prfx.substr(0,j);
        }
        return prfx;
    }
};