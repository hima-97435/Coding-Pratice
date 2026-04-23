class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indegree(numCourses,0);
      vector<vector<int>> adj(numCourses);
      int count =0;
      for ( auto node : prerequisites){
        int first= node[0];
        int second= node[1];
        adj[second].push_back(first);
        indegree[first]++;
      }  
      queue<int> q;

      for( int i=0;i<numCourses;i++){
        if(indegree[i] == 0) q.push(i);
      }
      while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for( int ni: adj[node]){
            indegree[ni]--;
            if(indegree[ni] == 0) q.push(ni);
        }
      }
      return count == numCourses;
    }
};
