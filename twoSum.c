// 1. 两数之和
// https://leetcode-cn.com/problems/two-sum/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0; i < numsSize; i++){
        int tmp = target - nums[i];
        for(int j=i+1; j < numsSize; j++){
            if(nums[j] != tmp) continue;
            *returnSize = 2;
            int* arr = (int*)malloc(sizeof(int)*2);
            arr[0] = i;
            arr[1] = j;
            return arr;
        }
    }
    *returnSize = 0;
    return NULL;
}
