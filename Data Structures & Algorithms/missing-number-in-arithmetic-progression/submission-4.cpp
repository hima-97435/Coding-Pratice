class Solution {
public:
    int missingNumber(vector<int>& arr) {
         int n = arr.size();
        int d = (arr[n-1]-arr[0])/n;

        int expected = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i] != expected) return expected;
            expected += d;
        }
        return expected;
    }
};
