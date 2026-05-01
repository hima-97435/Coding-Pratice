class Solution {
public:
    bool isValid(string sc) {
        stack<char> s;
        unordered_map<char, char> matp ={
            {')','('},
            {'}','{'},
            {']','['}
            
        };
        for(char c: sc){
            
            if(matp.count(c)) {
                if(!s.empty() && s.top() == matp[c]) s.pop(); 
           
                else  return false;
            }
            else s.push(c);
            
        }
        return s.empty();
    }
};
