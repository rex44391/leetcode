/*
* This algorithm's time complexity is O(n) 
* and use no extra space if return array doesn't count.
* The concept is easy. 
* For every number between 2^(n-1) and 2^n, 
* a number's number of 1 is just 2^(n-1)'s number of 1's 
* plus the number of 1's of the number that is its order's number starting from 2^(n-1)
*
* for example, consider 2^3= 8 to 2^4 = 16
* we know that 8 is 1000 and has only one 1
* 9 is just 8's number of 1 plus 1's number of 1 (Order = 1 from 8)
* because 9(1001) = 8(1000) + 1(0001)
* 10: 8's plus 2's (order = 2 from 8)
* because 10(1010) = 8(1000) + 2(0010)
* 11: 8's plus 3's
* 11(1011) = 8(1000) + 3(0011)
* and so on
* In addition, notice that there are 2^(n-1)'s number between 2^(n-1) and 2^n
* and this property let me know when a new segment start
* (that is, the loop arrive at 2^n)
* because of such properties, we can write a simple loop 
* to get the number of 1's for each number
* based on the previous number's result.
* all we have to do is to set the initial condition before the loop.
*/

int* countBits(int num, int* returnSize) {
    int *re = malloc(sizeof(int) * num + 1);
    *returnSize =num + 1;
    
    re[0] = 0;//init condition
    if(num == 0) return re;
    
    re[1] = 1;//init condition
    if(num == 1) return re;
    re[2] = 1;//init condition
    
    int start = 2;
    int ptr = 1;
    for(int i = 3; i < num + 1; i++) {
        if(ptr >= start) {
						//new segment, update start
            ptr = 1;
            start = i;
            re[i] = 1;
        } else {
            re[i] = 1 + re[ptr];
            ptr++;
        }
    }
    
    return re;
}
