class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(auto &s : operations){
            if(s == "C") ans.pop_back();
            else if(s == "+"){
                 int v1 = ans.back();
                 ans.pop_back();
                 int v2 = ans.back();
                 ans.push_back(v1);
                 ans.push_back(v1+v2);
            } 
            else if( s == "D") {
                int v1 = ans.back();
                ans.push_back(v1*2);
            } 
            else {
                ans.push_back(stoi(s));
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};