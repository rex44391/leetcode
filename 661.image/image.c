/* 
I just use the most intuitive algorithm
that is go through all elements in matrix, 
and compute the average value of every element and its surrounding cells
Stupid but super effective
*/

int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    if(MRowSize == 0 || MColSize == 0) return NULL;
    
    int **re = (int**)malloc(sizeof(int*) * MRowSize);
    *returnSize = MRowSize;
    columnSizes[0] = (int*)malloc(sizeof(int) * MRowSize);
    
    for(int i = 0; i < MRowSize;i++) {
        re[i] = (int*)malloc(sizeof(int)*MColSize);
        columnSizes[0][i] = MColSize;
    }
    
    for(int i = 0; i < MRowSize; i++) {
        for(int j = 0; j < MColSize; j++) {
            int counter = 0;
            int sum = 0;
            for(int x = i - 1; x <= i + 1; x++) {
                for(int y = j - 1; y <= j + 1; y++) {
                    if(x < 0 || y < 0 || x >= MRowSize || y >= MColSize) {
                        continue;
                    } else {
                        counter++;
                        sum += M[x][y];
                    }
                }
            }
            
            re[i][j] = sum / counter;
        }
    }
    return re;
}
