/*
* Honestly, when I pressed submit button, 
* I think this naive algorithm isn't correct 
* and even it is correct, it would be very slow.
* However it beats 7X percent of other submissions.
*/

int* constructRectangle(int area, int* returnSize) {
    int *re = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int L = pow(area, 0.5);
    int W = L;
    while(L*W != area) {
        if(L*W < area) {
            L++;
        } else {
            W--;
        }
    }
    re[0] = L;
    re[1] = W;
    return re;
}
