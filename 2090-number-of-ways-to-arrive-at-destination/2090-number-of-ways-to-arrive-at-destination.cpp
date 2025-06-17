class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        int MOD = 1e9 +7;
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto top = pq.top();
            long long distance = top.first;
            long long node = top.second;
            pq.pop();
            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long wt = it.second;
                if((wt + distance)<dist[adjnode]){
                    dist[adjnode]= (wt + distance);
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode] = ways[node];
                }else if(wt + distance==dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] +  ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};