class Solution {
public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line;
        int n =words.size();
        int length =0 ,i=0;
        while(i<n){
            if(length+words[i].size()+line.size() <= maxWidth) {
                line.push_back(words[i]);
                length+=words[i].size();
                i++;
            }
            else {
                int exspace = maxWidth-length;
                int rem = exspace%max(1,(int)line.size()-1);
                int space = exspace/max(1,(int)line.size()-1);
                for(int j=0;j<max(1,(int)line.size()-1); j++){
                    line[j]+=string(space,' ');
                    if(rem>0) {line[j]+=" "; rem--;}
                }
                string justified_line=accumulate(line.begin(), line.end(), string());
                res.push_back(justified_line);
                line.clear();
                length=0;
            }
        }
        string last_line=accumulate(line.begin(), line.end(), string(),[](string a, string b){
            return a.empty()?b:a+" "+b;
        });
        int trail_space = maxWidth-last_line.size();
        last_line+=string(trail_space,' ');
        res.push_back(last_line);
        return res;
    }
};