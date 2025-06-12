class Solution {
public:
    bool dfs(vector<vector<int>> & graph, vector<int>& color, int col,int start){
        color[start] = col;
        for(int i=0;i<graph[start].size();i++){
            if(color[graph[start][i]] == -1){
                if(dfs(graph,color,!col,graph[start][i]) == false)
                return false;
            }
                else if(color[graph[start][i]] == col){
                    return false;
                }
            
        } 
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
      
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph,color,0,i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};