/*

Link : https://leetcode.com/problems/network-delay-time/

Problem Statement :
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.



Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
*/

typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> g[n + 1];
        for (const auto& t : times) {
            g[t[0]].push_back(make_pair(t[1], t[2]));
        }
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(make_pair(0, k));
        int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf ? -1 : ans;
    }
    
};
