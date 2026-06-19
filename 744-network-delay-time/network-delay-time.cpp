class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i = 0 ; i < times.size(); i++){
            int u = times[i][0];
             int v = times[i][1];
              int w = times[i][2];

              adj[u].push_back({v,w});
        }

        vector<int>time(n+1,1e9);
        
        time[k] = 0;

        priority_queue<
           pair<int,int>,
           vector<pair<int,int>>,
           greater<pair<int,int>>
        >pq;

        pq.push({0,k});
        

        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
           
            if(dis > time[node]){
                continue;
            }
            for(auto [adjnode,wt] : adj[node]){
                if(wt + dis < time[adjnode]){
                    time[adjnode] = wt+dis;
                    pq.push({time[adjnode],adjnode});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(time[i] == 1e9){
                return -1;
            }
            maxi = max(time[i],maxi);
        }
        return maxi;
    }
};