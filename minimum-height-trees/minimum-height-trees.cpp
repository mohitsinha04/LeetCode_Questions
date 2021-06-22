class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
  vector<int> indegree(n, 0);
  
  for(auto e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
    indegree[e[0]]++;
    indegree[e[1]]++;
  }
  
  queue<int> q;
  for(int i = 0; i < n; i++) {
    if(indegree[i] == 1) {
      q.push(i);
    }
  }
  
  int remaining = n;
  vector<int> res; //<- size() 1 or 2
  while(!q.empty()) { // while (visited < n-2)
    int size = q.size();
    res = {};
    for(int i = 0; i < size; i++) {
      int curr = q.front();
      q.pop();
      remaining--;
      res.push_back(curr);
      for(auto i : adj[curr]) {
        if(--indegree[i] == 1) {
          q.push(i);
        }
      }
    }
  }
  
  
  for(int i = 0; i < n; i++) if(indegree[i] != 0) return {0};
  if(res.empty()) res.push_back(0);
  return res;
    }
};
