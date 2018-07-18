/*
* this kind of problem is easy and can be solved by an intuitive algorithm very effectively
* It's just very annoying when computing the index
* I have tried to figure out a function which can map the original array into the required 1D array
* but I failed, because in the case of row size != col size, the function would become very complicated
* So I step back to intuitive algorithm.
* First know how many diagonal the marix has
* Then figure out the start position of each diagonal
* finally copy the element of each diagonal 
*/

int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    int *re = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    *returnSize = matrixRowSize * matrixColSize;
    if(*returnSize == 1) {
        re[0] = matrix[0][0];
        return re;
    }
    
    int re_ptr = 0;
    int up[2] = {0, 0};
    int down[2];
    if(matrixColSize < 2) {
        down[0] = 1;
        down[1] = 0;
    } else {
        down[0] = 0;
        down[1] = 1;
    }
    
    
    for(int i = 0; i < (matrixRowSize + matrixColSize - 1); i++) {
        if(i % 2 == 0) { // go up
            int row = up[0];
            int col = up[1];
            while(row >= 0 && col < matrixColSize) {
                re[re_ptr] = matrix[row][col];
                row--;
                col++;
                re_ptr++;
            }
            
            for(int x = 0; x < 2; x++) {
                if(up[0] + 1 < matrixRowSize) {
                    up[0]++;
                } else {
                    up[1]++;
                }
            }
            
        } else { // go down
            int row = down[0];
            int col = down[1];
            while(row < matrixRowSize && col >= 0) {
                re[re_ptr] = matrix[row][col];
                row++;
                col--;
                re_ptr++;
            }
            for(int x = 0; x < 2; x++) {
                if(down[1] + 1 < matrixColSize) {
                    down[1]++;
                } else {
                    down[0]++;
                }
            }
        }
    }
    return re;
}
