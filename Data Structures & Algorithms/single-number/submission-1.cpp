class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // optmise space. -> declare a array of size of nums length()
        vector<int> space(2*10000+1,0);
        for( int x: nums) {
            if(x<0) space[10000+abs(x)]++;
            else space[x]++;
        }
        for( int i=0;i<2*10000;i++){
                if(space[i]%2 != 0){
                    if(i>10000) return 10000-i;
                    else return i;
                }
        }
        return -1;
    }
};
