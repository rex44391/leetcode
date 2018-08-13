

int findComplement(int num) {
    int a = (int)log2(num);
    a++;
    a = (int)pow(2, a);
    a--;
    return a^num;
}
