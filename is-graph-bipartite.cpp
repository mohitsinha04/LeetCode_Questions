class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 0) return true;
        vector<int> vis(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for(int e : graph[curr]) {
                        if(vis[e] == 0) {
                            vis[e] = (vis[curr] == 1) ? 2 : 1;
                            q.push(e);
                        } else {
                            if(vis[e] == vis[curr]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
