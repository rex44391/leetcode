/*
* I know when everyone see the requirement is O(logN) time, 
* They will solve this by divide and conquer(recursion)
* And although this algorithm runs in O(1/2n), it beast 100% of other submissions
* (its runtime is 0 ms and for divide and conquer algorithm, the runtime is 4ms)
* I found that there are some other magical methods(using bit operator)
* but for me, this one is not only very efficient 
* but also highly readable and understandable
*/

int singleNonDuplicate(int* nums, int numsSize) {
    for(int i = 0; i < numsSize - 1; i += 2) {
				//in this problem's setting
				//the single non duplicate is always in i position not i + 1
        if(nums[i] != nums[i + 1])
            return nums[i];
    }
    return nums[numsSize - 1];
    
}
