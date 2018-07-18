/*
* The algorithm is very straightforward, it's very easy to get it by reading my step-by step comment
*/


int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    
    //1. find the left or right skyline (get max element of each column)
    int *lrsky = malloc(sizeof(int) * (gridColSizes[0]));
    for(int i = 0; i < gridColSizes[0]; i++) {
        int max = -1;
        for(int j = 0; j < gridRowSize; j++) {
            if(grid[j][i] > max)
                max = grid[j][i];
        }
        lrsky[i] = max;
    }
                        
                        
    //2. find the top or down skyline (get max element of each row)
    int *tdsky = malloc(sizeof(int) * gridRowSize);
    for(int i = 0; i < gridRowSize; i++) {
        int max = -1;
        for(int j = 0; j < gridColSizes[0]; j++) {
            if(grid[i][j] > max)
                max = grid[i][j];
        }
        tdsky[i] = max;
    }
    
    //finaly try to get the minmum between lrsky[j] and tdsky[i], accumulate the difference of the min and matrix[i][j]
    int counter = 0;
    for(int i = 0; i < gridRowSize; i++) {
        for(int j = 0; j < gridColSizes[0]; j++) {
            int min;
            if(lrsky[j] < tdsky[i])
                min = lrsky[j];
            else
                min = tdsky[i];
            counter += (min-grid[i][j]);
        }
    }
    return counter;
}
