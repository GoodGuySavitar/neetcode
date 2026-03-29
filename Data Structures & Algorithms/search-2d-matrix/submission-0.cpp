class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0;
        int bot = row-1;

        while(top <= bot){
            row = (top + bot)/2;

            if(target > matrix[row][col-1]){
                top = row + 1;
            }
            else if(target < matrix[row][0]){
                bot = row - 1;
            }
            else {
                break;
            }
        }    
        
        if(!(top<=bot)){
            return false;
        }
        row = (top + bot)/2;
        int l = 0; int r = col-1;

        while(l <= r){
            int m = (l+r)/2;
            if(target > matrix[row][m]){
                l = m+1;
            }
            else if(target < matrix[row][m]){
                r = m-1;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};