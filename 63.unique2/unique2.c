int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(obstacleGridRowSize < 1 || obstacleGridColSize  < 1 || obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1])
        return 0;
    
    int flag = 0;
    for(int i = 0; i < obstacleGridRowSize; i++) {
        if(!flag) {
            if(obstacleGrid[i][0] != 1) {
                obstacleGrid[i][0] = -1;
            } else {
                flag = 1;
            }
        }
    }
    
    flag = 0;
    for(int i = 0; i < obstacleGridColSize; i++) {
        if(!flag) {
            if(obstacleGrid[0][i] != 1) {
                obstacleGrid[0][i] = -1;
            } else {
                flag = 1;
            }
        }
    }
    
    for(int i = 1; i < obstacleGridRowSize; i++) {
        for(int j = 1; j < obstacleGridColSize; j++) {
            if(obstacleGrid[i][j] == 1)
                continue;
            
            if(obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j-1] == 1) {
                obstacleGrid[i][j] = 0;
                continue;
            }
            if(obstacleGrid[i-1][j] == 1) {
                obstacleGrid[i][j] = obstacleGrid[i][j-1];
                continue;
            }
            if(obstacleGrid[i][j-1] == 1) {
                obstacleGrid[i][j] = obstacleGrid[i-1][j];
                continue;
            }
            obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
        }
    }
    
    return  obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1] * -1;
    
    
}
