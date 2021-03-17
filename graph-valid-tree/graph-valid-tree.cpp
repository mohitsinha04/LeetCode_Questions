class Solution {
public:
    int findset(int p, vector<int>& parent) {
        if(parent[p] != p) {
            parent[p] = findset(parent[p], parent);
        }
        return parent[p];
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(auto i : edges) {
            int x = findset(i[0], parent);
            int y = findset(i[1], parent);
            if(x == y) return false;
            parent[x] = y;
        }
        return true;
    }
};
/*

int findset(int p, vector<int>& parent) {
  if(parent[p] != p) {
    parent[p] = findset(parent[p], parent);
  }
  return parent[p];
}

bool isValid_Tree(int n, vector<vector<int>>& edges) {
  if(edges.size() != n - 1) return false;
  vector<int> parent(n);
  for(int i = 0; i < 5000; i++)
    parent[i] = i;
  for(auto i : edges) {
    int x = findset(i[0], parent);
    int y = findset(i[1], parent);
    if(x == y) return false;
    parent[x] = y;
  }
  return true;
}
/*
    // cycle detection patterns:
    // - cycle detection is backtracking to build all paths and making sure there is no cycle.
    // - visited is the state that is updated.
    // - can have memo to track nodes that are not involved in cycles
    // - dfs always works. bfs, dsu work when graph is undirected.

// bfs
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if (edges.size () != n-1)
            return false;
        
        vector <vector <int>> graph (n);
        for (auto edge : edges)
        {
            // mistake: always add both edges for undirected graph
            graph [edge [0]].push_back (edge [1]);
            graph [edge [1]].push_back (edge [0]);
        }
        
        queue <int> q;
        q.push (0);
        
        // lesson learnt: standard way to detect cycle in undirected graph.
        unordered_map <int, int> parents;
        parents [0] = -1;
        
        while (!q.empty ())
        {
            int node = q.front ();
            q.pop ();
            
            for (auto nbor : graph [node])
            {
                // lesson learnt: reuse parent to identify trivial loops/cycles.
                if (parents [node] == nbor)
                    continue;
                
                if (parents.count (nbor))
                    return false;
                
                q.push (nbor);
                parents [nbor] = node;
            }
        }
        
        // mistake: always think of disconnected graph
        return parents.size () == n;
    } */