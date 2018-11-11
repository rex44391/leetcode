/*
* use recursive with a table recording the result to solve this problem
* it works but not very effective, it would be much faster if you just use dynamic programming
* to bottom-up buildy the solution
*/


double recur(double **table, long poured, int row, int col) {//return the volume of outflow
    if(row == 0) {
        if(poured <= 1)
            return 0;
        else
            return (double)((poured - 1) * 250 ) / 2.0;
    }
    
    double left = 0.0;
    double right = 0.0;
    if(col - 1 >= 0) {
        if(table[row-1][col-1] != -1.0) {
            left = table[row-1][col-1];
        } else {
            table[row-1][col-1] = recur(table, poured, row - 1, col - 1);
            left = table[row-1][col-1];
        }
    }
    if(col < row) {
        if(table[row - 1][col] != -1.0) {
            right = table[row - 1][col];
        } else {
            table[row - 1][col] = recur(table, poured, row - 1, col);
            right = table[row - 1][col];
        }
    }
    
    double sum = left + right;
    if(sum > 250.0) {
        sum -= 250.0;
        return sum /= 2.0;
    } else
        return 0.0;
}


double champagneTower(long poured, int query_row, int query_glass) {
    if(query_row == 0) {
        if(poured >= 1)
            return 1.0;
        else
            return 0;
    }
    
    double left = 0.0;
    double right = 0.0;
    double **table = malloc(sizeof(double*) * 100);
    for(int i = 0; i < 100; i++) {
        table[i] = malloc(sizeof(double) * 101);
        for(int j = 0; j < 101; j++)
            table[i][j] = -1.0;
    }
    
    
    if(query_glass - 1 >= 0)
        left = recur(table, poured, query_row - 1, query_glass - 1);
    if(query_glass < query_row)
        right = recur(table, poured, query_row - 1, query_glass);
    
    if(left + right > 250.0)
        return 1.0;
    else if(left + right == 0.0)
        return 0.0;
    else
        return (left + right) / 250.0;
}
