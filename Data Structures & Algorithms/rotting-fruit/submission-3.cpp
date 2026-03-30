class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = 0;
        int fresh = 0;

        queue<pair<int, int>> q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                else if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int level = q.size();

            for(int l = 0; l < level; l++){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int f = a + dirs[i][0];
                    int s = b + dirs[i][1];

                    if(f < 0 || s < 0 || f >= rows || s >= cols || grid[f][s] != 1){
                        continue;
                    }

                    grid[f][s] = 2;
                    fresh--;
                    q.push({f,s});
                }
            }
            total++;
        }
        if(fresh > 0){
            return -1;
        }
        return total;
    }
};
