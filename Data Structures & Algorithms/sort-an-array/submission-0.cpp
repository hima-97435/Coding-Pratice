class Solution {
    private:
    void merge(vector<int>&arr, int l , int r, int m ){
        vector<int> temp;
        int left = l;
        int right = m+1;
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]) {
                temp.push_back(arr[left]);
                left++;

            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m){
            temp.push_back(arr[left]);
            left++;

        }
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
            
        }
        for( int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }

    }
    private:
    void mergesort(vector<int>& nums, int l , int r){
        if(l >= r) return;
        int md = l+(r-l)/2;
        mergesort(nums,l,md);
        mergesort(nums,md+1,r);
        merge(nums, l,r,md);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
         mergesort(nums,0,nums.size()-1);
         return nums;
    }
};