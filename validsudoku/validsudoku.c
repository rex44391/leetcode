bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    //check row
    bool *check = (bool*)malloc(sizeof(bool) * 9);
    for(int i = 0; i < boardRowSize; i++) {
        for(int j = 0; j < boardColSize; j++) {
            check[j] = false;
        }
        for(int j = 0; j < boardColSize; j++) {
            if(board[i][j] == '.')
                continue;
            int pos = board[i][j] - '0' - 1;
            
            if( check[pos] ) {
                return false;
            } else {
                check[pos] = true;
            }
        }
    }
    
    //check column
    for(int i = 0; i < boardColSize;i++) {
        for(int j = 0; j < boardRowSize; j++) {
            check[j] = false;
        }
        for(int j = 0; j < boardRowSize; j++) {
            if(board[j][i] == '.')
                continue;
            
            int pos = board[j][i] - '0' - 1;
            if( check[pos] ) {
                return false;
            } else {
                check[pos] = true;
            }
        }
    }
    
    //check 3*3
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < boardRowSize; k++) {
                check[k] = false;
            }
            for(int k = i * 3; k < (i * 3 + 3); k++) {
                for(int l = j * 3; l < (j * 3 + 3) ; l++) {
                    if(board[k][l] == '.')
                        continue;
                    
                    int pos = board[k][l] - '0' - 1;
                    if( check[pos] ) {
                        return false;
                    } else {
                        check[pos] = true;
                    }       
                }    
            }
            
        }
    }
    
    return true;
}
