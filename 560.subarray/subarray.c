/* Again, I used the most intuitive algorithm here!
 * Just loop the array, make the pointed element as a start of subarray,
 * and check how many subarray it can form(the inner loop).
 * And please remember, do not break out the inner loop once the sum equal to or greater than k, 
 * because the array may have minus integers 
 * and therefore a start position may form numerous subarrays whose sum is equal to k.
 * This algorithm beats about other 80% submissions.
 */

int subarraySum(int* nums, int numsSize, int k) {
    int counter = 0;
    for(int i = 0; i < numsSize; i++) {
        int sum = 0;
        for(int j = i; j < numsSize; j++) {
            sum += nums[j];
            if(sum == k) 
                counter++;
        }
        
    }
    return counter;
}
