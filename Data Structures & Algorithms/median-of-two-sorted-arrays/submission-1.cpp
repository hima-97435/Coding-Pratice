class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2= nums2.size();
        vector<int> merged(l1+l2);
        copy(nums1.begin(), nums1.end() , merged.begin());
        copy(nums2.begin(), nums2.end(), merged.begin()+l1);
        sort(merged.begin(), merged.end());
        int n= merged.size();
        if(n%2 == 0){
            return (merged[n/2-1] +merged[n/2])/2.0;
        }
        else return merged[n/2];
    }
};
