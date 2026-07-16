class StockSpanner {
public:
        vector<int> ans;

    StockSpanner() {
    }
    
    int next(int price) {
        if(ans.empty()){
            ans.push_back(price);
            cout<<price<<" "<<endl;
            return 1;
        }
        else {
            ans.push_back(price);
            int n = ans.size();
            int cnt =1;
            int val = price;
            for(int i=n-2;i>=0;i--){
                if(ans[i]>val) break;
                cnt++;
            }
            return cnt;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */