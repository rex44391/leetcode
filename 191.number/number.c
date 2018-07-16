int hammingWeight(uint32_t n) {
    int counter = 0;
    while(n > 0) {
        if(n % 2 == 1)
            counter++;
        n = n / 2;
    }
    return counter;
}
