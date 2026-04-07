class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        unordered_set<string>vis;

        queue<pair<string ,int>>q;
        q.push({"0000",0});
        vis.insert("0000");

        while(!q.empty()){
            auto[curr,steps] = q.front();
            q.pop();

            if(curr == target) return steps;
            if(dead.count(curr)) continue;
            

            for(int i = 0 ; i<4 ; i++){
                string up = curr;
                string down = curr;

                up[i] = (curr[i] == '9') ? '0' : curr[i]+1;
                down[i] = (curr[i] == '0') ? '9' : curr[i]-1;

                if(!vis.count(up)){
                    vis.insert(up);
                    q.push({up,steps+1});
                }
                if(!vis.count(down)){
                    vis.insert(down);
                    q.push({down,steps+1});
                }
            }
        }
        return -1;
    }
};