int** generateMatrix(int n) {
    int **re = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        re[i] = malloc(sizeof(int) * n);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            re[i][j] = -1;
        }
    }
    
    
    int counter = 1;
    int n_square = n * n;
    int x = 0;
    int y = 0;
    char direction = 'r';
    while(counter <=  n_square) {
        re[x][y] = counter;
        if(direction == 'r') {
            if( (y + 1) < n && (re[x][y+1] == -1) ) {
                y++;
            } else {
                direction = 'd';
                x++;
            }
            counter++;
            continue;
        }
        
        
        if(direction == 'd') {
            if( (x + 1) < n && (re[x+1][y] == -1) ) {
                x++;
            } else {
                direction = 'l';
                y--;
            }
            counter++;
            continue;
        }
        
        if(direction == 'l') {
            if( (y-1) > -1 && (re[x][y-1] == -1) ) {
                y--;
            } else {
                direction = 'u';
                x--;
            }
            counter++;
            continue;
        }
        
        if(direction == 'u') {
            if( (x-1) > -1 && (re[x-1][y] == -1) ) {
                x--;
            } else {
                direction = 'r';
                y++;
            }
            counter++;
            continue;
        }
        
        
    }
    return re;
}
