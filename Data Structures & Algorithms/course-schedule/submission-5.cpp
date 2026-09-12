class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for( auto & t: prerequisites){
            int course = t[0];
            int pre = t[1];
            adj[course].push_back(pre);
            indegree[pre]++;
        }
        queue<int> q;
        for( int x=0;x<numCourses;x++){
            if(indegree[x] == 0) q.push(x);
        }
        int completedcourses=0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            numCourses--;
            for( int next: adj[current]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        return 0==numCourses;
    }
};
