class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int half = (total+1)/2;
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int l =0 , r = nums1.size();
        while(l<=r){
            int i = (l+r)>>1; // element up which we will take elements for num1
            int j = half-i; // elements which for nums2

            int alft = i>0?nums1[i-1]:INT_MIN;
            int argt = i<nums1.size()?nums1[i]:INT_MAX;
            int blft = j>0?nums2[j-1]:INT_MIN;
            int brgt = j<nums2.size()?nums2[j]:INT_MAX;
            if(alft<=brgt and blft<=argt) {
                if(total%2!= 0) return max(alft,blft);
                else return (max(alft,blft)+min(argt,brgt))/2.0;
            }
            else if(alft<brgt) l=i+1;
            else r=i-1;
        }
        return -1;
    }
};
