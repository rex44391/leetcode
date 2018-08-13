


int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    if((numsRowSize * numsColSize) != (r * c) ) {
        columnSizes[0] = malloc(sizeof(int) * numsRowSize);
        for(int i = 0; i < numsRowSize; i++)
             columnSizes[0][i] = numsColSize;
        *returnSize = numsRowSize;
        return nums;
    }
    
    int **re = (int**)malloc(sizeof(int*) * r);
    columnSizes[0] = malloc(sizeof(int) * r);
    for(int i = 0; i < r; i++) {
        re[i] = (int*)malloc(sizeof(int) * c);
        columnSizes[0][i] = c;
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int row =  (i*c+j) / numsColSize;
            int col = (i*c+j) % numsColSize;
            re[i][j] = nums[row][col];
        }
    }
    
    *returnSize = r;

    
    return re;
}
