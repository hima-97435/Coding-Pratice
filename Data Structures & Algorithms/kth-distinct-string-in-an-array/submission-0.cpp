class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct, seen;
        for(const string&s : arr){
            if(distinct.count(s)) {
                distinct.erase(s);
                seen.insert(s);
            }
            else if(!seen.count(s)) distinct.insert(s);
        }
        for(const string &s :arr){
            if(distinct.count(s)){
                k--;
                if(k == 0) return s;
            }
        }
        return "";
    }
};