class Solution {
public:

    string encode(vector<string>& strs) {
        // call decode function
        
        string an="";

            for(const string & s: strs){
                
                // decode(s);
                an+=to_string(s.size())+"#"+s;
            }

            return an;
    }

    vector<string> decode(string s) {
        vector<string> res ;
        int i=0;
        while(i<s.size()){
            int j = i;
            // we are doing it , so that we could get all possible num
            // ex 333#... it will treat 333 ass string size  right

            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+length;
            res.push_back(s.substr(i,length));
            i=j;


        }
        return res;
    }
};
