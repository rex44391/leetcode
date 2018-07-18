/*
* This algorithm is straightforward
* I just create another array and write down each element's next state and copy back
* It beats 100% of other submissions, but its space complexity is O(n).
*/

void gameOfLife(int** board, int boardRowSize, int *boardColSizes) {
    int **memo = malloc(sizeof(int*) * boardRowSize);
    for(int i = 0; i < boardRowSize; i++) {
        memo[i] = malloc(sizeof(int) * boardColSizes[0]);
    }
    
    for(int i = 0; i < boardRowSize; i++) {
        for(int j = 0; j < boardColSizes[0]; j++) {
            int counter = 0;
            for(int x = i - 1; x <= i + 1; x++) {
                for(int y = j - 1; y <= j + 1; y++) {
                    if(x >= 0 && x < boardRowSize && y >= 0 && y < boardColSizes[0]) {
                        if(board[x][y] == 1)
                            counter++;
                    }
                }
            }
            
            if(board[i][j] == 1) {
                counter--;
                memo[i][j] = 1;
                if(counter < 2 || counter > 3)
                    memo[i][j] = 0;
                
            } else {
                memo[i][j] = 0;
                if(counter == 3)
                    memo[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < boardRowSize; i++) {
        for(int j = 0; j < boardColSizes[0]; j++) {
            board[i][j] = memo[i][j];
        }
    }

}
