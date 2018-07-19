/*
* sum up all the number in the array, and sum of 1~n
* the difference is the answer
*/

int missingNumber(int* nums, int numsSize) {
    int counter = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        counter += nums[i];
        sum += (i + 1);
    }
    return sum - counter;
}
