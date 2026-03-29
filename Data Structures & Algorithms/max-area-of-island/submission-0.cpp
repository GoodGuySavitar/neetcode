class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;    
        int curr = 0;

        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                dfs(grid, r, c, curr);
                ans = max(ans, curr);
                curr = 0;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& curr){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return;
        }

        grid[r][c] = 0;
        curr++;
        for(int i = 0; i < 4; ++i){
            dfs(grid, r + directions[i][0], c + directions[i][1], curr);
        }
    }
};
