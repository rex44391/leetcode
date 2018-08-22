/*
* using recursive which is slightly easiler than iterative to solve this
* Again, the algorithm itself is easy and beats 100% of submissions,
* but to implement it is troublesome
*/

char* countAndSay(int n) {
    if(n == 1) return "1";
    char *n1 = countAndSay(n - 1);
    char prev = n1[0];
    int counter = 1;
    int ptr = 1;
    char *re = malloc(sizeof(char) * 5000);
    int re_size = 0;
    
    while(n1[ptr] != '\0') {
        if(n1[ptr] != prev) {
            //write counter
            char *temp = malloc(sizeof(char) * 20);
            int temp_size = 0;
            while(counter > 0) {
                temp[temp_size] = (counter % 10) + '0';
                temp_size++;
                counter /= 10;
            }
            for(int i = temp_size - 1; i >= 0; i--) {
                re[re_size] = temp[i];
                re_size++;
            }
            //write prev
            re[re_size] = prev;
            re_size++;
            
            
            //update prev
            prev = n1[ptr];
            counter = 1;
            free(temp);
        } else {
            counter++;  
        } 
        ptr++;
    }
    
    //write counter
    char *temp = malloc(sizeof(char) * 20);
    int temp_size = 0;
    while(counter > 0) {
        temp[temp_size] = (counter % 10) + '0';
        temp_size++;
        counter /= 10;
    }
    for(int i = temp_size - 1; i >= 0; i--) {
        re[re_size] = temp[i];
        re_size++;
    }
    //write prev
    re[re_size] = prev;
    re_size++;
    re[re_size] = '\0';
    re_size++;
    return re;
}
