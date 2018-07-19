int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    if(matrixRowSize == 0 || matrixColSize == 0) return NULL;
    int *re = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    int ptr = 0;
    for(int i = 0 ; i < matrixRowSize; i++) {
        for(int j = 0; j < matrixColSize; j++) {
            re[ptr] = matrix[i][j];
            ptr++;
        }
    }
    qsort(re, matrixRowSize*matrixColSize, sizeof(int), cmpfunc);
    return re[k - 1];
}
