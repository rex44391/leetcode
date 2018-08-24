/*
* The concept is easy just using simple math 
* to calculate n is in which number and in which digit of that number
* Yet it really took me a while to figure out a correct formula to do this 
*/

int findNthDigit(int n) {
    long num_no = 9;
    long digit_num = 1;
    while(n > (num_no * digit_num)) {
        n -= (num_no * digit_num);
        num_no *= 10;
        digit_num++;
    }
    
		//get the number here
		//be careful the coner case like INT_MAX
		//that why I use long rather than int
    long start = (long)pow(10 ,(digit_num - 1) );
    if(n % digit_num == 0) {
        start = start + (n / digit_num) - 1;
    } else {
        start = start + (n / digit_num);
    }
    int order = n % digit_num;//get the digit pos here
    if(order == 0) {
        return start % 10;
    } else {
        order = digit_num - order;
        while(order > 0) {
            start /= 10;
            order--;
        }
        return start % 10;
    }
}
