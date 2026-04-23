class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
       int n = a.size();
        vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = 1;
    suffix[n-1] = 1;

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * a[i-1];
    }

    for (int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * a[i+1];
    }
    vector<int> ans ;
    for( int i=0;i<n;i++){
        ans.push_back(suffix[i]*prefix[i]);
    }
    return ans;
    }
};
/*
[1,2,4,6]
prefix = [1,2,8,48]
suffix= [48,24,6,1]
*/
