/*
* straight-forward one, beats 100%
*/

int surfaceArea(int** grid, int gridRowSize, int *gridColSizes) {
    if(!grid || gridRowSize == 0 || gridColSizes[0] == 0) return 0;
    
    int total = 0;
    for(int i = 0; i < gridRowSize; i++) {
        for(int j = 0; j < gridColSizes[i]; j++) {
            if(grid[i][j] == 0) continue;
            int count = grid[i][j] * 4 + 2;
            int sub = 0;
            if(j < gridColSizes[i] - 1) {//check right
                if(grid[i][j] < grid[i][j + 1])
                    sub += (grid[i][j] * 2);
                else
                    sub += (grid[i][j + 1] * 2);
            }
            if(i < gridRowSize - 1) {//check left
                if(grid[i][j] < grid[i + 1][j])
                    sub +=  (grid[i][j] * 2);
                else
                    sub += (grid[i + 1][j] * 2);
            }
            count -= sub;
            
            if(count > 0)
                total += count;
        }
    }
    return total;
}
