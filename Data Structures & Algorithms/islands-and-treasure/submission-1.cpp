class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i){
                int j = r + dirs[i][0];
                int k = c + dirs[i][1];

                if(j < 0 || k < 0 || j >= rows || k >= cols || grid[j][k] != INT_MAX){
                    continue;
                }

                grid[j][k] = grid[r][c] + 1;
                q.push({j, k});
            }
        }
    }
};
