/*
* Again, using dynamic programming to get sum in a region in O(1) time
*/

typedef struct {
    int **table;
    int rowSize;
    int colSize;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    NumMatrix *nm = malloc(sizeof(NumMatrix));
    nm->table = malloc(sizeof(int*) *matrixRowSize);
    nm->rowSize = matrixRowSize;
    nm->colSize = matrixColSize;

    for(int i = 0; i < matrixRowSize; i++) {
        nm->table[i] = malloc(sizeof(int) * matrixColSize);
    }
    
    int sum = 0;
    for(int i = 0; i < matrixColSize; i++) {
        sum += matrix[0][i];
        nm->table[0][i] = sum;
    }
    sum = 0;
    for(int i = 0; i < matrixRowSize; i++) {
        sum += matrix[i][0];
        nm->table[i][0] = sum;
    }
    
    for(int i = 1; i < matrixRowSize; i++) {
        for(int j = 1; j < matrixColSize; j++) {
            nm->table[i][j] = matrix[i][j] + nm->table[i - 1][j] + nm->table[i][j - 1] - nm->table[i - 1][j - 1];
        }
    }
    return nm;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if(!obj) return NULL;
    
    int a = obj->table[row2][col2];
    int b = 0;
    int c = 0;
    int d = 0;
    
    if(row1 > 0 && col1 > 0) {
        b = obj->table[row2][col1 - 1];
        c = obj->table[row1 - 1][col2];
        d = obj->table[row1 - 1][col1 - 1];
    } else if(row1 > 0) {
        c = obj->table[row1 - 1][col2];
    } else if(col1 > 0) {
        b = obj->table[row2][col1 - 1];
    }
    
    return a - b - c + d;
}

void numMatrixFree(NumMatrix* obj) {
    if(!obj)return;
    for(int i = 0; i < obj->rowSize; i++)
        free(obj->table[i]);
    free(obj->table);
    free(obj);
}
