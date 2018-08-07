

int arrToNum(int *a, int last) {
    int multi = 1;
    int counter = 0;
    for(int i = 0; i < last; i++) {
        counter += a[i] * multi;
        multi *= 10;
    }
    
    return counter;
}

int maximumSwap(int num) {
    if(num == 0) return 0;
    
    int len = 10;
    int *num_arr = malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++) {
        num_arr[i] = 0;
    }
    
    int temp = num;
    int arr_ptr = 0;
    while(temp > 0) {
        num_arr[arr_ptr] = temp % 10;
        temp /= 10;
        arr_ptr++;
    }
    
    if(arr_ptr == 1) return num;
    
    int max = -1;
    for(int i = 0; i < arr_ptr - 1; i++) {
        for(int j = i; j < arr_ptr; j++) {
            int temp = num_arr[i];
            num_arr[i] = num_arr[j];
            num_arr[j] = temp;
            int result = arrToNum(num_arr, arr_ptr);
            
            if(result > max)
                max = result;
            
            temp = num_arr[i];
            num_arr[i] = num_arr[j];
            num_arr[j] = temp;

        }
    }
    return max;
}
