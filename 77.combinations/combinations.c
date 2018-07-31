/*
* Using recursive to solve this problem.
* C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
* The only difficult part is how to compute the index of the array
* when you write the answer into the array.
*/

int **re;

int count(n, k) {
    if(n == k) return 1;
    if(k == 1) return n;
    
    long long counter = 1;
    for(int i = (n - k + 1); i <= n; i++)
        counter *= i;
    for(int i = 1; i <= k; i++)
        counter /= i;
    return (int)counter;
}


void recur(int n, int k, int start, int end) {
    if(n == k) { //init condition
        for(int i = 0; i < k; i++) {
            re[start][i] = i + 1;
        }
        return;
    }
    for(int i = start; i <= end; i++) {
        re[i][k - 1] = n;
    }
    
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            re[start + i][0] = i + 1;
        }
    } else {
        recur(n - 1, k - 1, start, start + count(n - 1, k - 1) - 1);
        recur(n - 1, k, start + count(n - 1, k - 1), end);
    }
}


int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int re_size = count(n , k);
    
    re = malloc(sizeof(int*) * re_size);
    columnSizes[0] = malloc(sizeof(int) * re_size);
    for(int i = 0; i < re_size; i++) {
        re[i] = malloc(sizeof(int) * k);
        columnSizes[0][i] = k;
    }
    
    
    *returnSize = re_size;
    recur(n, k, 0, re_size - 1);
    return re;
}
