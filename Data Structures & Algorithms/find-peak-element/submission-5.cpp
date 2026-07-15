class Solution {
   public:
    int findPeakElement(vector<int>& s) {
        int n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]) return i;
        }
        return n-1;
    }
};