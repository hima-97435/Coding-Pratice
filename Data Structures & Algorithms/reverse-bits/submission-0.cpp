class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // make value
        // logic which i came up is like you have sme number with bits as 100000...1
        // when 1 comes kep it as place and when 0 comes in unitl next 1 left shift bu how many times 0 comes.
    
        // simple
       int result = 0;
    for (int i = 0; i < 32; i++) {
        // 1. Shift result left to make space for the incoming bit
        result <<= 1;
        
        // 2. Get the last bit of n (n & 1) and add it to result
        // Using OR (|) is common here
        result |= (n & 1);
        
        // 3. Shift n right to process the next bit in the next loop
        n >>= 1;
    }
    return result;
    }
};
