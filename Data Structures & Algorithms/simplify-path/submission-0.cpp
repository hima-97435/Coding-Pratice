class Solution {
public:
    string simplifyPath(string s) {
      vector<string> st;
      string curr ;
      for(char c: s+"/"){
        if(c == '/'){
            if(curr =="..") {
                if(!st.empty()) st.pop_back();

            }
            else if(!curr.empty() && curr!= ".") {
                st.push_back(curr);
            }
            curr.clear();
        }
        else {
            curr+=c;
        }
      }
      string sr ="/";
      for( int i=0;i<st.size();i++){
        if(i>0) sr+="/";
        sr+=st[i];
      }
      return sr;

    }
};