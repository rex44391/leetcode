/*
* just followed the problem's instruction to shift the letter
*/

char* shiftingLetters(char* S, int* shifts, int shiftsSize) {
    for(int i = shiftsSize - 2; i >= 0; i--) {
        shifts[i] += shifts[i + 1];
        shifts[i] %= 26;
    }
    
    char *re = malloc(sizeof(char) * (shiftsSize + 1) );
    
    for(int i = 0; i < shiftsSize; i++) {
        int temp =  S[i] - 'a';
        temp += shifts[i];
        temp %= 26;
        re[i] = 'a' + temp;
    }
    
    
    re[shiftsSize] = '\0'; 
    return re;
}
