class Solution {
public:
    bool isHappy(int n) {
        int slow = n , fast = sumofsqaure(n);
        while(slow!=fast){
            fast=sumofsqaure(fast);
            fast=sumofsqaure(fast);
            slow=sumofsqaure(slow);
        }
        return fast == 1;
    }
    int sumofsqaure(int n){
        int output=0;
        while(n>0){
            output+=(n%10)*(n%10);
            n/=10;
        }
        return output;
    }
};
