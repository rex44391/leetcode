int hIndex(int* citations, int citationsSize) {
    int *temp = malloc(sizeof(int) * citationsSize);
    for(int i = 0; i < citationsSize; i++)
        temp[i] = citations[citationsSize - i - 1];
        
        
    for(int i = 0; i < citationsSize; i++) {
        if(temp[citationsSize - i - 1] >= (citationsSize - i) )
            return citationsSize - i;
    }
    return 0;
}
