class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = digits[0];
        for(int i=1;i<digits.size();i++){
            num=num*10+digits[i];
            cout<<"number: "<<num<<" ";
            // cout<<digits[i]<<" ";
        }
        cout<<endl;
        cout<<num<<endl;

        num+=1;
        cout<<num<<endl;
        vector<int> ans;
        while(num>0){
            int temp = num%10;
            ans.push_back(temp);
            num/=10;
        }
        reverse(ans.begin(), ans.end());
    return ans;
    }
};
