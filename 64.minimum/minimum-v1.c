/*
* We know that the last step of shortest path to grid[i][j] 
* is either from grid[i][j-1] or grid[i-1][j]
* So I use recursion to find the minimum path of grid[i][j-1] and grid[i-1][j].
* It's very inefficient and cannot pass the test in time!
*/

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int re = 0;
    if(gridRowSize == 1) {
        for(int i = 0; i < gridColSize; i++) {
            re += grid[0][i];
        }
        return re;
    }
    if(gridColSize == 1) {
        int re = 0;
        for(int i = 0; i < gridRowSize; i++) {
            re += grid[i][0];
        }
        return re;
    }
    
    int upper = minPathSum(grid, gridRowSize - 1, gridColSize);
    int left = minPathSum(grid, gridRowSize, gridColSize - 1);
    if(upper < left) {
        return grid[gridRowSize - 1][gridColSize - 1] + upper;
    } else {
        return grid[gridRowSize - 1][gridColSize - 1] + left;
    }
}
