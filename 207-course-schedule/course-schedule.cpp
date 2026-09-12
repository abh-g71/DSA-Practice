class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(int i = 0 ; i < prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        if(q.empty()){
            return false;
        }
        int ans = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;

            for(auto x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(numCourses == ans){
            return true;
        }
        return false;
    }
};