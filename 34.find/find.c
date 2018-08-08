/* 
* using recursion to find the target.
* surely, the finding time is O(lgN), 
* but I think finding the boundary of target in second stage exceeds O(lgN).
* Please tell me if you have better way for second stage.
*/

int found;

void recur(int *nums, int left, int right, int target) {
    if(found > -1) return;
    
    if(left >= right) {
        if(nums[left] == target)
            found = left;
        return;
    }
    
    int middle = (left + right) / 2;
    if(nums[middle] == target)
        found = middle;
    else if(nums[middle] < target)
        recur(nums, middle + 1, right, target);
    else
        recur(nums, left, middle - 1, target );
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    found = -1;
    recur(nums, 0, numsSize - 1, target);
    
    int *re = malloc(sizeof(int) * 2);
    *returnSize = 2;
    if(found == -1) {
        re[0] = -1;
        re[1] = -1;
    } else {
        int left = found;
        int right = found;
        while(nums[left] == target && left >= 0) {
            left--;
        }
        while(nums[right] == target && right < numsSize) {
            right++;
        }
        left++;
        right--;
        re[0] = left;
        re[1] = right;
    }
    return re;
}
