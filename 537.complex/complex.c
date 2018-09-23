/*
* This one is easy. I use straight-forward algorithm and beats 100% of other submissions
* However, implementing the algo is very annoying, 
* since you need to deal with the conversion
* between string and number on your own
*/

void parse(char *input, int *real, int *imag) {
    *real = 0;
    *imag = 0;
    int *temp = malloc(sizeof(int) * 10);
    int temp_size = 0;
    int ptr = 0;
    int multi = 1;
    
    //real
    bool is_minus = false;
    if(input[ptr] == '-') {
        is_minus = true;
        ptr++;
    }
    while(input[ptr] != '+') {
        temp[temp_size] = input[ptr] - '0';
        temp_size++;
        ptr++;
    }
    for(int i = temp_size - 1; i >= 0; i--) {
        *real += (temp[i] * multi);
        multi *= 10;
    }
    if(is_minus)
        *real *= -1;
    
    //imag
    ptr++;
    is_minus = false;
    temp_size = 0;
    multi = 1;
    
    if(input[ptr] == '-') {
        is_minus = true;
        ptr++;
    }
    while(input[ptr] != 'i') {
        temp[temp_size] = input[ptr] - '0';
        temp_size++;
        ptr++;
    }
    for(int i = temp_size - 1; i >= 0; i--) {
        *imag += (temp[i] * multi);
        multi *= 10;
    }
    if(is_minus)
        *imag *= -1;
    
    free(temp);    
}


char* complexNumberMultiply(char* a, char* b) {
    int a_real = 0;
    int b_real = 0;
    int a_imag = 0;
    int b_imag = 0;
    
    parse(a, &a_real, &a_imag);
    parse(b, &b_real, &b_imag);

    
    char *re = malloc(sizeof(char) * 500);
    int re_size = 0;
    int re_real = 0;
    int re_imag = 0;
    re_real += a_real * b_real;
    re_real += (-1 * (a_imag * b_imag));
    re_imag += (a_real * b_imag) + (a_imag * b_real);
    
    char *temp = malloc(sizeof(char) * 500);
    int temp_size = 0;

    if(re_real == 0) {
        re[re_size] = '0';
        re_size++;
    } else if(re_real < 0) {
        re[re_size] = '-';
        re_size++;
        re_real *= -1;
    }
    
    while(re_real > 0) {
        temp[temp_size] = (re_real % 10) + '0';
        temp_size++;
        re_real /= 10;
    }
    for(int i = temp_size - 1; i >= 0; i--) {
        re[re_size] = temp[i];
        re_size++;
    }
    temp_size = 0;
    re[re_size] = '+';
    re_size++;
    
    if(re_imag == 0) {
        re[re_size] = '0';
        re_size++;
    } else if(re_imag < 0) {
        re[re_size] = '-';
        re_size++;
        re_imag *= -1;
    }
    
    while(re_imag > 0) {
        temp[temp_size] = (re_imag % 10) + '0';
        temp_size++;
        re_imag /= 10;
    }
    for(int i = temp_size - 1; i >= 0; i--) {
        re[re_size] = temp[i];
        re_size++;
    }
    
    re[re_size] = 'i';
    re_size++;
    re[re_size] = '\0';
    return re;
}
