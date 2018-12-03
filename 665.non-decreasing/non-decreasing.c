

bool checkPossibility(int* nums, int numsSize) {
    if(numsSize == 1) return true;
    int break_point = -1;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i - 1] > nums[i]) {
            break_point = i;
            break;
        }
    }
    
    if(break_point == -1 || break_point == numsSize - 1) {
        return true;
    } else if(break_point == 1) {
        for(int i = 2; i < numsSize; i++) {
            if(nums[i - 1] > nums[i]) {
                return false; 
            }
        }
        return true;
    } else {
        //change previous
        bool worked = true;
        if(break_point < 2) {
            worked = false;
        } else {
            if(nums[break_point - 2] > nums[break_point]) {
                worked = false;
            } else {
                for(int i = break_point + 1; i < numsSize; i++) {
                    if(nums[i - 1] > nums[i]) {
                        worked = false;
                        break;
                    }
                }
            }
        }
        //change myself
        if(worked) {
            return true;
        } else {
            if(nums[break_point - 1] > nums[break_point + 1]) {
                return false;
            } else {
                for(int i = break_point + 1; i < numsSize; i++) {
                    if(nums[i - 1] > nums[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    
    return false;
}
