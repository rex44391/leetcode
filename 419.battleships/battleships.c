/*
* solving this in one pass, using only O(1) and without modifying the value of the array
*/

int countBattleships(char** board, int boardRowSize, int boardColSize) {
    int counter = 0;
    for(int i = 0; i < boardRowSize; i++) {
        for(int j = 0; j < boardColSize; j++) {
            if(board[i][j] == '.') continue;
            bool left = true;
            bool up = true;
            if( (j - 1) > -1 && board[i][j - 1] == 'X') {
                left = false;
            }
            if( (i - 1) > -1 && board[i-1][j] == 'X') {
                up = false;
            }
            if(left && up)
                counter++;
        }
    }
    return counter;
}
