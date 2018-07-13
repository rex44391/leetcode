void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    if(matrixRowSize < 2)
        return;
    
    int circle = matrixRowSize / 2;
    int c = 0;
    int temp, temp2;
    while(c < circle) {
        for(int y = c; y <  matrixRowSize - c - 1; y++) {
            //first step
            temp = matrix[y][matrixRowSize-c-1];
            matrix[y][matrixRowSize-c-1] = matrix[c][y];
            
            //second step
            temp2 = matrix[matrixRowSize-c-1][matrixRowSize-y-1];
            matrix[matrixRowSize-c-1][matrixRowSize-y-1] = temp;
            
            //third step
            temp = matrix[matrixRowSize-y-1][c];
            matrix[matrixRowSize-y-1][c] = temp2;
            
            //forth step
            matrix[c][y] = temp;
        }        
        c++;
    }
}
