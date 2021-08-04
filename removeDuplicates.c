// 26. 删除有序数组中的重复项
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int* nums, int numsSize){
    if(numsSize < 1) return 0;
    int cur = 0;
    for(int i=1; i < numsSize; i++){
        if(nums[cur] != nums[i]){
            nums[++cur] = nums[i];
        }
    }
    return cur+1;
}
