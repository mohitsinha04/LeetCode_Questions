class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses], in(numCourses, 0);
        queue<int> q;
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        for(int i = 0; i < in.size(); i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : graph[curr]) {
                if(--in[i] == 0) q.push(i);
            }
        }
        for(int i = 0; i < in.size(); i++) {
            if(in[i] != 0) return false;
        }
        return true;
    }
};