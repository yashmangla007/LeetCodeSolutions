class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int delrow[4] = {0, -1, 0, 1};
        int delcol[4] = {-1, 0, 1, 0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 &&
                    grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]) count++;
            }
        }

        return count;
    }
};