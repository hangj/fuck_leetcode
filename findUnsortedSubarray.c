// 581. 最短无序连续子数组
// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/


// find the biggest element that less than or equal to value in sorted array
int findstart(int* nums, int numsSize, int value){
    int i=0,j=numsSize-1;
    for(; i < j-1; ){
        int k = (i+j)/2;
        if(nums[k] < value){
            i = k;
            continue;
        }
        if(nums[k] > value){
            j = k;
            continue;
        }
        return k;
    }
    if(nums[j] <= value) return j;
    if(nums[i] > value) return -1;
    return i;
}

int findUnsortedSubarray(int* nums, int numsSize){
    if(numsSize < 2) return 0;

    int start = -1, stop = -1; // (start, stop]
    int max = 0;

    for(int i=1; i < numsSize; i++){
        if(nums[i] > nums[max]) max = i;
        if(nums[i] < nums[i-1]){
            // find a start
            start = findstart(nums, i, nums[i]);
            stop = i;
            break;
        }
    }
    if(stop == -1) return 0; // sorted

    for(int i=stop+1; i < numsSize; i++){
        if(start != -1 && nums[i] < nums[start]){
            start = findstart(nums, i, nums[i]);
        }
        if(nums[i] >= nums[max]){
            max = i;
            continue;
        }
        stop = i;
    }

    return stop - start;
}










