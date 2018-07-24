bool check(int **grid, int row, int column) {
    int *a = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++) {
        a[i] = 0;
    }
    for(int i = row; i < row + 3; i++) {
        for(int j = column; j < column + 3; j++) {
            if(grid[i][j] > 9 || grid[i][j] < 1)
                return false;
            else {
                a[grid[i][j]]++;
                if(a[grid[i][j]] > 1)
                    return false;
            }
            
        }
    }
    free(a);
    
    
    int number = 0;
    for(int i = column; i < column + 3; i++)//get number
        number += grid[row][i];
    
    for(int i = row + 1; i < row + 3; i++) { //check row sum
        int temp = 0;
        for(int j = column; j < column + 3; j++)
            temp += grid[i][j];
        
        if(temp != number)
            return false;
    }
    
    for(int i = column; i < column + 3; i++) {
        int temp = 0;
        for(int j = row; j < row + 3; j++) {
            temp += grid[j][i];
        }
        if(temp != number)
            return false;
    }
    
    
    int diag1 = 0;
    int diag2 = 0;
    for(int i = 0; i < 3; i ++) {//check diagonal
        diag1 += grid[row + i][column + i];
        diag2 += grid[row + i][column + 2 - i];
    }
    if(diag1 != number)
        return false;
    if(diag2 != number)
        return false;
    

    return true;
}


int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes) {
    int counter = 0;
    for(int i = 0; i < gridRowSize - 2; i++) {
        for(int j = 0; j < gridColSizes[i] - 2; j++) {
            if(check(grid, i, j))
                counter++;
        }
    }
    return counter;
}
