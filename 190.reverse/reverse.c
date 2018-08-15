
uint32_t reverseBits(uint32_t n) {
    uint32_t counter = 0;
    int multi = 31;
    
    while(multi > -1) {
        counter += (n % 2) * (uint32_t)pow(2, multi);
        n = n >> 1;
        multi--;
    }
    return counter;
}
