class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] =true;
        for(int i=0;i<isConnected[0].size();i++){
            if(isConnected[node][i] && visited[i] == false){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int numberOfComponents =0;
      int n = isConnected.size();
      vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numberOfComponents++;
                dfs(isConnected,visited,i);
            }
        }
        return numberOfComponents;
    }
};