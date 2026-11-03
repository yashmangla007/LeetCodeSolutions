class Solution {
public:

    void dfs(int vertex, vector<vector<int>> &adj, vector<int> &vis){
        vis[vertex] = 1;
        for(int i=0 ; i<adj[vertex].size(); i++){
            if(adj[vertex][i]!=0 && !vis[i]){
                dfs(i, adj, vis);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int v = isConnected.size();

        vector<int> vis(v, 0);

        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                count++;
            }
        }

        return count;
    }
};