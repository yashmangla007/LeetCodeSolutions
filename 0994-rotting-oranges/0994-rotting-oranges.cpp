class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));

        int time = 0;
        //adding initial 2s to the queue:
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    visited[i][j] = 2;
                    q.push({{i,j},time});
                }
            }
        }

        int drow[4] = {0, -1, 0, 1};
        int dcol[4] = {-1, 0, 1, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            q.pop();
            visited[row][col] = 2;


            for(int i=0; i<4; i++){
                int nrow = row +drow[i];
                int ncol = col +dcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m &&
                   grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    q.push({{nrow, ncol}, time+1});
                    visited[nrow][ncol] = 1;
                }
            }

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0) return -1;
            }
        }

        return time;       
    }
};