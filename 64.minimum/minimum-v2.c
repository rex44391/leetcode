/*
* This time I use same idea but with dynamic programming to find the shortest path
* Then it achieves 100%!
*/

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int **table = malloc(sizeof(int*) * gridRowSize);
    for(int i = 0; i < gridRowSize; i++) {
        table[i] = malloc(sizeof(int) * gridColSize);
    }
    
    table[0][0] = grid[0][0];
    for(int i = 1; i < gridRowSize; i++) {
        table[i][0] = grid[i][0] + table[i - 1][0];
    }
    
    for(int i = 1; i < gridColSize; i++) {
        table[0][i] = grid[0][i] + table[0][i - 1];
    }
    
    for(int i = 1; i < gridRowSize; i++) {
        for(int j = 1; j < gridColSize; j++) {
            if(table[i - 1][j] > table[i][j - 1]) {
                table[i][j] = grid[i][j] + table[i][j - 1];
            } else {
                table[i][j] = grid[i][j] + table[i - 1][j];
            }
        }
    }
    
    
    return table[gridRowSize - 1][gridColSize - 1];
}
