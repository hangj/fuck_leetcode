// 413. 等差数列划分
// https://leetcode-cn.com/problems/arithmetic-slices/



// 等差数列数列的长度为 n，返回子数组个数
#define fuck(n) ((n)<3?0: ((n)-1)*((n)-2)/2)

int numberOfArithmeticSlices(int* nums, int numsSize){
    if(numsSize < 3) return 0;

    int sum = 0;
    int diff = nums[1] - nums[0];
    int len=2;
    for(int i=2; i<numsSize; i++){
        if(diff == nums[i] - nums[i-1]){
            len++;
        }else{
            sum += fuck(len);

            diff = nums[i] - nums[i-1];            
            len = 2;
        }
    }
    return sum + fuck(len);
}
