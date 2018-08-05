int projectionArea(int** grid, int gridRowSize, int *gridColSizes) {
    int top = 0;//get how many non zero element
    int row = 0;
    int col = 0;
    
    for(int i = 0; i < gridRowSize; i++) {
        int max = 0;
        for(int j = 0; j < gridColSizes[0]; j++) {
            if(grid[i][j] > 0) {//get top
                top++;
            }
            if(grid[i][j] > max) {
                max = grid[i][j];
            }
        }
        row += max;
    }
    
    for(int i = 0; i < gridColSizes[0]; i++) {
        int max = 0;
        for(int j = 0; j < gridRowSize; j++) {
            if(grid[j][i] > max) {
                max = grid[j][i];
            }
        }
        col += max;
    }
    
    
    return top + row + col;
}
