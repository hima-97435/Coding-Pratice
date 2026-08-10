class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int median1 = 0, median2 = 0;
        for (int z = 0; z < (n + m) / 2 + 1; z++) {
            median2 = median1;
            if (i < n and j < m) {
                if (nums1[i] > nums2[j]) {
                    median1 = nums2[j];
                    j++;
                } else {
                    median1 = nums1[i];
                    i++;
                }
            } else if (i < n) {
                median1 = nums1[i];
                i++;
            } else {
                median1 = nums2[j];
                j++;
            }
        }
        if ((n + m) % 2 == 1)
            return (double)median1;
        else
            return (median1 + median2) / 2.0;
    }
};
