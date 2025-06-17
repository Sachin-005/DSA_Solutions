class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {stops, {node, totalCost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, p] = q.front(); q.pop();
            int node = p.first;
            int cost = p.second;

            if (stops > k) continue;

            for (auto &[adjNode, weight] : adj[node]) {
                if (cost + weight < dist[adjNode]) {
                    dist[adjNode] = cost + weight;
                    q.push({stops + 1, {adjNode, cost + weight}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
