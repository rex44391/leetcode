int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize == 0 || matrixColSize == 0) return NULL;
    
    int size = matrixRowSize * matrixColSize;
    int *re = (int*)malloc(sizeof(int) * size);
    bool **check = (bool**)malloc(sizeof(bool*) * matrixRowSize);
    for(int i = 0; i < matrixRowSize; i++) {
        check[i] = (bool*)malloc(sizeof(bool) * matrixColSize);
    }
    
    for(int i = 0; i < matrixRowSize; i++) {
        for(int j = 0; j < matrixColSize; j++) {
            check[i][j] = false;
        }
    }
    
    int ptr = 0;
    char direction = 'r';
    int x = -1;
    int y = 0;
    while(ptr < size) {
        if(direction == 'r') {
            if( (x + 1) < matrixColSize && check[y][x+1] == false) {
                x++;
                re[ptr] = matrix[y][x];
                check[y][x] = true;
                ptr++;
                continue;
            } else {
                direction = 'd';
            }
        }
        
        if(direction == 'd') {
            if((y + 1) < matrixRowSize && check[y+1][x] == false) {
                y++;
                re[ptr] = matrix[y][x];
                check[y][x] = true;
                ptr++;
                continue;
            } else {
                direction = 'l';
            }
        }
        
        if(direction == 'l') {
            if( (x-1) > -1 && check[y][x-1] == false) {
                x--;
                re[ptr] = matrix[y][x];
                check[y][x] = true;
                ptr++;
                continue;
            } else {
                direction = 'u';
            }
        }
        
        if(direction == 'u') {
            if( (y-1) > -1 && check[y-1][x] == false) {
                y--;
                re[ptr] = matrix[y][x];
                check[y][x] = true;
                ptr++;
                continue;
            } else {
                direction = 'r';
            }
        }

    }
    
    
    return re;
}
