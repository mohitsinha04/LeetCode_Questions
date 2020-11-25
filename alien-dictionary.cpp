class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<int>> graphs;
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                indegree[words[i][j]] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            string curr = words[i];
            string next = words[i + 1];
            int min_len = min(curr.size(), next.size());
            for(int j = 0; j < min_len; j++) {
                if(curr[j] != next[j]) {
                    unordered_set<int> set = graphs[curr[j]];
                    if(!set.count(next[j])) {
                        graphs[curr[j]].insert(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }
                if(j == min_len - 1 && curr.size() > next.size()) return "";
            }
        }
        queue<char> q;
        string res = "";
        for(auto i : indegree) {
            if(i.second == 0)
                q.push(i.first);
        }
        while(!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            if(graphs[curr].size() > 0) {
                for(auto i : graphs[curr]) {
                    indegree[i]--;
                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
        }
        return res.size() == indegree.size() ? res : "";
    }
};
