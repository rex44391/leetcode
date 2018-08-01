/*
 * The algorithm is just like how human do when multiplying two numbers
 * Implementing it is a little bit complex
 * The most important part, though, is to generate a legit string in C
 */

char* multiply(char* num1, char* num2) {
    
    
    int num1_len = 0;
    int num2_len = 0;
    while(num1[num1_len] != '\0')
        num1_len++;
    while(num2[num2_len] != '\0')
        num2_len++;
    
    if(num1_len == 1 && num1[0] == '0') {
        char *a = "0";
        return a;
    }
    if(num2_len == 1 && num2[0] == '0') {
        char *a = "0";
        return a;
    }
    
    int result_size = num1_len + num2_len;
    int *result = malloc(sizeof(int) * result_size );
    for(int i = 0; i < result_size; i++) {
        result[i] = 0;
    }
    
    for(int i = num1_len - 1; i >= 0; i--) {
        for(int j = num2_len - 1; j >= 0; j--) {
            int add_pos = i + j + 1;
            int temp = num1[i] - '0';
            int temp2 = num2[j] - '0';
            temp *= temp2;
            
            result[add_pos] += temp;
            int carry;
            while(result[add_pos] > 9 && add_pos > -1) {
                carry = result[add_pos] / 10;
                result[add_pos] %= 10;
                add_pos--;
                result[add_pos] = result[add_pos] + carry;
            }
        }
    }
    
    //copy to char for return
    int start = 0;
    while(result[start] == 0)
        start++;

    char *re = malloc(sizeof(char) * (result_size - start + 1) );
    re[(result_size - start)] = '\0';
    for(int i = 0; i < (result_size -start); i++) {
        re[i] = result[start + i] + '0';
    }
    
    return re;
}
