class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto & t : prerequisites){
            int course = t[0];
            int pre = t[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for( int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);

        }
        vector<int> order;
        while(!q.empty()){
            int courr  = q.front();
            q.pop();
            order.push_back(courr);
            for( int next : adj[courr]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);

            }
        }
        if(order.size() == numCourses) return order;
        return {};
        
    }
};
