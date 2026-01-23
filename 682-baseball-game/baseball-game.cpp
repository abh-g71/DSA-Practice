class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for (auto &op : ops) {
            if (op == "+") {
                int s = st.back() + st[st.size()-2];
                st.push_back(s);
            }
            else if (op == "D") {
                st.push_back(st.back() * 2);
            }
            else if (op == "C") {
                st.pop_back();
            }
            else {
                st.push_back(stoi(op));
            }
        }
        
        int sum = 0;
        for (int x : st) sum += x;
        return sum;
    }
};
