int count(int length) {
    if(length < 3)
        return 0;

    int counter = 0;
    for(int i = 3; i <= length; i++) {
        counter += (length - i + 1);
        
    }
    return counter;
}


int numberOfArithmeticSlices(int* A, int ASize) {
    if(ASize < 3) return 0;
    int counter = 0;
    int prev_index = 0;
    int prev_diff = A[1] - A[0];
    for(int i = 2; i < ASize; i++) {
        int temp = A[i] - A[i - 1];
        if(temp != prev_diff) {
            counter += count(i - prev_index);
            prev_index = i - 1;
            prev_diff = temp;
        }
    }
    
    if(prev_index != ASize - 1) {
        counter += count(ASize - prev_index);
    }
    
    return counter;
}
