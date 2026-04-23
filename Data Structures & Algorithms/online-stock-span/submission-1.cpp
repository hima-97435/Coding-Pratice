class StockSpanner {
    // stack<int> st;
    vector<int> ans;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
       ans.push_back(price);
       int cnt =0;
       int n = ans.size();
       for( int i=n-1;i>=0;i-- ){
        // if(x> price) break;
        // cnt ++;
        if(ans[i] > price) break;
        cnt++;
       }
       return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */