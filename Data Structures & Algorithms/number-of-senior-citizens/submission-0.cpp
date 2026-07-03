class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;

        for(auto &s : details){
            string temp = s.substr(11 , 2);
            cout<<temp<<endl;
            int num = stoi(temp);
            if(num > 60){
                cnt++;
            }
        }

        return cnt;
    }
};