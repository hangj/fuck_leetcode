// 283. 移动零
// https://leetcode-cn.com/problems/move-zeroes/


void moveZeroes(int* nums, int numsSize){
    for(int i=0,j=0; i < numsSize; j++){
        if(j >= numsSize){
            nums[i++] = 0;
            continue;
        }
        if(nums[j] == 0) continue;

        nums[i++] = nums[j];
    }
}
