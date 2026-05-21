class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int > pq;
        for( int x: stones) pq.push(x);
        while(pq.size()>1){
            int t1 = pq.top();
            pq.pop();
            int t2= pq.top();
            pq.pop();
            if(t1>t2) pq.push(t1-t2);
            else pq.push(0);
        }
        return pq.top();
    }
};
