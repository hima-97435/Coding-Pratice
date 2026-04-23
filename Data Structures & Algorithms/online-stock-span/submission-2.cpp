class StockSpanner {
    stack<pair<int , int>> sta;
    // stores [price, span]

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
       int span =1;
       while(!sta.empty() && sta.top().first<=price) {
        span+=sta.top().second;
        sta.pop();
       }
       sta.push({price, span});
       return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */