class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // make value
        // logic which i came up is like you have sme number with bits as 100000...1
        // when 1 comes kep it as place and when 0 comes in unitl next 1 left shift bu how many times 0 comes.
    
        // simple
        int rs =0;
        for( int i=0;i<32;i++){
            rs<<=1;
            rs|=(n&1);
            n>>=1;
        }
        return rs;
    }
};
