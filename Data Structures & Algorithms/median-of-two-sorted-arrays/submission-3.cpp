class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int half = (total+1)/2;
        if(nums2.size()<nums1.size()) swap(nums1,nums2);
        int  m = nums1.size(), n= nums2.size();
        int l =0 , r = nums1.size();
        while(l<=r){
            int i = (l+r)>>1;
            int j = half-i;

            int aleft = i>0?nums1[i-1]:INT_MIN;
            int aright = i<m?nums1[i]:INT_MAX;
            int bleft = j>0?nums2[j-1]:INT_MIN;
            int bright = j<n?nums2[j]:INT_MAX;

            if(aleft<=bright and bleft<=aright) {
                if(total%2 != 0) return max(aleft,bleft);
                else return (max(aleft,bleft)+min(aright,bright))/2.0;
            }
            else if(aleft>bright) r=i-1;
            else l=i+1;
        }       
        return -1;
    }
};
