class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0;i<tickets.size();i++) q.push(i);
        int time =0;
        while(!q.empty()){
            time++;
            int curr = q.front();
            q.pop();
            tickets[curr]--;
            if(tickets[curr] == 0 ){ if(curr == k) {return time;}}
            else q.push(curr);
        }
        return time;
    }
};