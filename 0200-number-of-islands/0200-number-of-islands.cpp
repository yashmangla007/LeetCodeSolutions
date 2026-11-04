class Solution {
public:
    void bfs(vector<vector<char>> &adj 
            ,vector<vector<int>> &vis
            ,int row, int col){
        int v= adj.size();
        int x = adj[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // for(int delr = -1; delr<=1; delr++){
            //     for(int delc = -1; delc<=1; delc++){
            //         int nrow = row+delr;
            //         int ncol = col+delc;

            //         if( (nrow>=0 && nrow<v && ncol>=0 && ncol <x)
            //         &&  (!vis[nrow][ncol] && adj[nrow][ncol]=='1')){
            //             vis[nrow][ncol] = 1;
            //             q.push({nrow, ncol});
            //         }
                    
            //     }
            // }

            int direc[4][2] = {{row, col+1},
                               {row+1, col},
                               {row, col-1},
                               {row-1, col}};

            for(int i=0; i<4; i++){
                int nrow = direc[i][0];
                int ncol = direc[i][1];
                if( (nrow>=0 && nrow<v && ncol>=0 && ncol <x)
                        &&  (!vis[nrow][ncol] && adj[nrow][ncol]=='1')){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }

        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid, vis, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};