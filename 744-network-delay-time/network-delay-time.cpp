class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v,w});
            
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push({0,k});
        int time = 0;

        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            if(t > dist[node]) continue;
            

            for(auto [nei,w] : adj[node]){
                if(t+w < dist[nei]){
                    dist[nei] = t+w;
                    pq.push({dist[nei],nei});
                }
            }
        }
        for(int i = 1; i < n+1 ; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            time = max(time,dist[i]);
        }
        return time;
    }
};