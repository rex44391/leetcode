int uniquePaths(int m, int n) {
    int **route =  (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) {
        route[i] = (int *)malloc(m*sizeof(int));
    } 
    
    for(int i = 0; i < m; i++) {
        route[0][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        route[i][0] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j ++) {
            route[i][j] = route[i-1][j] +  route[i][j-1];
        }
    }
    int re = route[n-1][m-1];
    return re;
}
