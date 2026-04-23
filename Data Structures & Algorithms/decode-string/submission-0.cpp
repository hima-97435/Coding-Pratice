class Solution {
public:
    string decodeString(string s) {
        vector<string> stringstack;
        vector<int> countstack;
        string cur="";
        int k =0;
        for(char c: s){
            if(isdigit(c)) k = k*10+(c-'0');
            else if( c == '[') {
                stringstack.push_back(cur);
                countstack.push_back(k);
                cur="";
                k=0;
            }
            else if(c == ']'){
                string temp =cur;
                cur = stringstack.back();
                stringstack.pop_back();
                int count = countstack.back();
                countstack.pop_back();
                for( int i=0;i<count;i++) {
                    cur+=temp;
                }
            }
            else cur+=c;
        }
        return cur;
    }
};