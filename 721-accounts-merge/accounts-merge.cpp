class Solution {
public:

    unordered_map<string,vector<string>>graph;
    unordered_set<string>vis;
    unordered_map<string,string>emailToname;

    void dfs(string email,vector<string> &temp){
        vis.insert(email);
        temp.push_back(email);

        for(auto nei : graph[email]){
            if(!vis.count(nei)){
                dfs(nei,temp);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &acc : accounts){
            string name = acc[0];

            for(int i = 1; i < acc.size();i++){
                emailToname[acc[i]] = name;
                if(i==1) continue;

                graph[acc[i]].push_back(acc[i-1]);
                graph[acc[i-1]].push_back(acc[i]);
            }
        }

        vector<vector<string>>res;

        for(auto &it : emailToname){
            string email = it.first;

            if(!vis.count(email)){
                vector<string>temp;
                dfs(email,temp);
                sort(temp.begin(),temp.end());

                vector<string>account;
                account.push_back(emailToname[email]);
                account.insert(account.end(),temp.begin(),temp.end());

                res.push_back(account);
            }
        }
        return res;
    }
};