class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq1;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq2;

        for(int i = 0; i < n; i++) {
            pq1.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            while(!pq2.empty() && pq2.top()[0] <= time) {

                int w = pq2.top()[1];
                int index = pq2.top()[2];

                pq2.pop();
                pq1.push({w, index});
            }

            if(pq1.empty()) {

                time = pq2.top()[0];

                while(!pq2.empty() && pq2.top()[0] <= time) {

                    int w = pq2.top()[1];
                    int index = pq2.top()[2];

                    pq2.pop();
                    pq1.push({w, index});
                }
            }

            int x = pq1.top().first;
            int y = pq1.top().second;

            pq1.pop();

            ans.push_back(y);

            pq2.push({(int)(time + tasks[i]), x, y});
        }

        return ans;
    }
};