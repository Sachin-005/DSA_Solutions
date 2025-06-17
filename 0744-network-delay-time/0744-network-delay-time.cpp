class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>>adjList(n+1);
        for(int i=0; i<times.size(); i++){
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, k});

        vector<int>dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();

            for(auto edge: adjList[node]){
                int edgeNum = edge.first;
                int edgeWt = edge.second;

                if(wt+edgeWt < dist[edgeNum]){
                    dist[edgeNum] = wt + edgeWt;
                    pq.push({dist[edgeNum], edgeNum});
                } 
            }
        }
        int maxi = -1;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            if(maxi< dist[i])maxi = dist[i];
        }
        return maxi;
    }
};