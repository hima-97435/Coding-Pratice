class Solution {
public:
    bool isaplhanum(char s){
        return (s>='a' && s<='z' || s>='A' && s<='Z'  || s>='0' && s<='9' );
         
    }
    bool isPalindrome(string s) {
        int i =0, j = s.size()-1;
        while(i<j){
            
            while(i<j && !isaplhanum(s[i])) i++;
            while(i<j && !isaplhanum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
