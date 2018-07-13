/* this algorithm is simple and effective
*/
bool search(int* nums, int numsSize, int target) {
    bool found = false;
    for(int i = 0; i < numsSize; i++) {
        if(target == nums[i])
            return true;
    }
    return found;
}
