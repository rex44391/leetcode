/*
* just compute the length of six edges formed by the for points
* Then, sorting them and check their properties
*/


int cmpfunc (double * a, double * b) {
    if(*a >= *b) return 1;
    else return 0;

}

double cal(int *pA, int *pB) {
    double x = pow(pA[0] - pB[0], 2);
    double y = pow(pA[1] - pB[1], 2);
    return x+y;
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    double *length = malloc(sizeof(double) * 6);
    length[0] = cal(p1, p2);
    length[1] = cal(p1, p3);
    length[2] = cal(p1, p4);
    length[3] = cal(p2, p3);
    length[4] = cal(p2, p4);
    length[5] = cal(p3, p4);
    
    qsort(length, 6, sizeof(double), cmpfunc);
    
    for(int i = 0; i < 6; i++)
        printf("%f, ", length[i]);
    printf("\n");
    
    if(length[0] != length[3] || length[4] != length[5] || length[3] >= length[4] ) {
        return false;
    }
    
    if(length[0] + length[3] != length[5]) {
        return false;
    }
    
    return true;
}
