class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0), res;
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int curr = q.front();
                res.push_back(curr);
                q.pop();
                for(auto p : adj[curr]) {
                    if(--indegree[p] == 0)
                        q.push(p);
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] != 0) return {};
        }
        return res;
    }
};